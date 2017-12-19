#include "PhysicsManager.h"
#include "GameManager.h"
US_NS_JK


PhysicsManager* PhysicsManager::_instance = nullptr;

PhysicsManager::PhysicsManager()
{
}

PhysicsManager::~PhysicsManager()
{
}

void PhysicsManager::attachRigidbody(RigidBody* rigidbody)
{
	_rigidBodies.push_back(rigidbody);
}

void PhysicsManager::detachRigidbody(RigidBody* rigidbody)
{
	const auto rb = std::find(_rigidBodies.begin(), _rigidBodies.end(), rigidbody);
	_rigidBodies.erase(rb);
}




void PhysicsManager::update()
{
	for(auto rigid:_rigidBodies)
	{
		rigid->_collidingBodies.clear();
	}

	if (!_rigidBodies.empty())
	{
		for (auto rigid : _rigidBodies)
		{
			const auto deltaTime = GameManager::getInstance()->getDeltaTime();

			const auto mass = rigid->getDensity() * rigid->getSize().getWidth()*rigid->getSize().getHeight();

			// v = v + (1 / m * F) * dt; 
			rigid->setVelocity(Vec2(rigid->getVelocity() + rigid->getForces()*(1 / mass)*deltaTime) + Vec2(0, 400.0f) * rigid->getGravityScale() * deltaTime);

			// x = x + v * dt;
			rigid->setPosition(Vec2(rigid->getPosition() + rigid->getVelocity()*deltaTime));
		}

		// Duyệt tất cả các Objects
		for (auto it1 = 0; it1 <= _rigidBodies.size() - 1; it1++)
		{
			for (auto it2 = it1 + 1; it2 <= _rigidBodies.size() - 1; it2++)
			{
				Manifold manifold;
				if (_rigidBodies[it1]->isActived() && _rigidBodies[it2]->isActived())
				{
				//	if (_rigidBodies[it1]->getBodyType() == DYNAMIC && _rigidBodies[it2]->getBodyType() == STATIC)
					{
						if (AABBvAABB(_rigidBodies[it1], _rigidBodies[it2], manifold))
						{
							(_rigidBodies[it1])->_collidingBodies.push_back((_rigidBodies[it2])->_tag);
							(_rigidBodies[it2])->_collidingBodies.push_back((_rigidBodies[it1])->_tag);
							resolveCollision(manifold);
						}
					}
				}

				//if(sweptAABB(*it1,*it2,manifold)<1.0f) // có va chạm
				//{
				//	// v = v*swept
				//	(*it1)->setVelocity((*it1)->getVelocity()*sweptAABB(*it1, *it2, manifold));
				//}
				//// x = x + v * dt;
				//(*it1)->setPosition(Vec2((*it1)->getPosition() + (*it1)->getVelocity()*GameManager::getInstance()->getDeltaTime()));
			}

#pragma region XAMLONE
			//// Nếu Object đang xét là DYNAMIC thì thực hiện tiếp
			//if ((*it1)->getBodyType() == DYNAMIC)
			//{
			//	// Nếu vận tốc = 0 thì đâu có di chuyển mà xét :)))~
			//	if ((*it1)->getVelocity() != Vec2(0.0f, 0.0f))
			//	{
			//		// Ý tưởng là duyệt hết các phần từ (trừ phần tử đang xét = A) với các collider còn lại
			//		// nếu collider nào có thể va chạm với A và gần A nhất thì lôi ra xét :)))~			

			//		// Vị trí Object gần A nhất
			//		auto nearestIt1 = INFINITY;

			//		// Duyệt hết các phần tử trong mảng
			//		for (auto it2 = _rigidBodies.begin(); it2 != it1 && it2 != _rigidBodies.end(); ++it2)
			//		{
			//			// Khoảng cách giữa 2 vật là căn bậc 2 của ((X2 - X1)^2 + (Y2 - Y1)^2)
			//			const auto currentPosition = sqrt(pow((*it2)->getPosition().getX() - (*it1)->getPosition().getX(), 2) + pow((*it2)->getPosition().getY() - (*it1)->getPosition().getY(), 2));

			//			Manifold manifold;
			//			// Nếu collider đang xét có thể va chạm với A (it1) và có vị trí gần nhất A nhất
			//			// Nếu ở frame sau có va chạm thì swept < 1
			//			// Khi 2 vật đang va chạm ở frame này thì swept trả về 1
			//			if (sweptAABB(*it1, *it2, manifold) < 1.0f && currentPosition < nearestIt1)
			//			{
			//				nearestIt1 = currentPosition;
			//				resolveCollision(manifold);
			//			}
			//		}
			//	}
			//}
#pragma endregion 
		}
	}
}







float PhysicsManager::sweptAABB(RigidBody* a, RigidBody *b, Manifold& manifold) {
	// Entry là khoảng cách gần nhất giữa 2 vật để bắt đầu va chạm
	// Exit là khoảng cách gần nhất giữa 2 vật để va chạm kết thúc
	float dxEntry;
	float dxExit;
	float dyEntry;
	float dyExit;

	manifold.rigid1 = a;
	manifold.rigid2 = b;

	// Hệ trục tọa độ được xét là:
	//		trục X: từ trái sang phải
	//		trục Y: từ trên xuống dưới


	// Xét theo trục X
	if (a->getVelocity().getX() > 0)
	{
		dxEntry = b->getPosition().getX() - (a->getPosition().getX() + a->getSize().getWidth());
		dxExit = (b->getPosition().getX() + b->getSize().getWidth()) - a->getPosition().getX();
	}
	else // Vật di chuyển ngược lại
	{
		dxEntry = (b->getPosition().getX() + b->getSize().getWidth()) - a->getPosition().getX();
		dxExit = b->getPosition().getX() - (a->getPosition().getX() + a->getSize().getWidth());
	}


	// Xét theo trục Y
	if (a->getVelocity().getY() > 0)
	{
		dyEntry = b->getPosition().getY() - (a->getPosition().getY() + a->getSize().getHeight());
		dyExit = (b->getPosition().getY() + b->getSize().getHeight()) - a->getPosition().getY();
	}
	else // Vật di chuyển ngược lại
	{
		dyEntry = (b->getPosition().getY() + b->getSize().getHeight()) - a->getPosition().getY();
		dyExit = b->getPosition().getY() - (a->getPosition().getY() + a->getSize().getHeight());
	}


	// Tính thời gian tối thiểu khi bắt đầu va chạm và thời gian tối thiểu khi kết thúc va chạm
	// time = distance / velocity
	float txEntry;
	float txExit;
	float tyEntry;
	float tyExit;

	// mày không di chuyển thì làm sao mà tới đích được chứ :)))))~
	// Xét theo trục X
	if (a->getVelocity().getX() == 0.0f)
	{
		txEntry = -INFINITY;
		txExit = INFINITY;
	}
	else // mày đã chịu di chuyển rồi đó :D
	{
		txEntry = dxEntry / a->getVelocity().getX();
		txExit = dxExit / a->getVelocity().getX();
	}


	// Xét theo trục Y
	if (a->getVelocity().getY() == 0.0f)
	{
		tyEntry = -INFINITY;
		tyExit = INFINITY;
	}
	else
	{
		tyEntry = dyEntry / a->getVelocity().getY();
		tyExit = dyExit / a->getVelocity().getY();
	}


	// Để 2 vật va chạm thì cả 2 trục X và Y phải ĐỒNG THỜI xảy ra va chạm
	// Do đó ta cần lấy thời gian lớn nhất của txEntry và tyEntry
	const auto entryTime = max(txEntry, tyEntry);

	// Để 2 vật kết thúc va chạm thì chỉ cần 1 trong 2 trục kết thúc va chạm thôi. Phải hong ? :)))~
	// Do đó ta lấy thời gian nhỏ nhất giữa txExit và tyExit
	const auto exitTime = min(txExit, tyExit);


	if (entryTime > exitTime ||							// Khi vật đang rời đi thời gian sẽ âm, và thời gian Entry sẽ bé hơn thời gian Exit
		(txEntry < 0.0f && tyEntry < 0.0f) ||			// Khi thời gian âm là vật đang rời đi
		txEntry > 1.0f ||								// Thời gian lớn hơn 1 tức là quãng đường đi cần thiết để va chạm sẽ 
		tyEntry > 1.0f)									//		lớn hơn vật tốc => ở frame sau sẽ không xảy ra va chạm
	{
		return 1.0f;		// không có va chạm
	}

	// có va chạm ở frame sau
	else
	{
		// calculate normal of collided surface
		if (txEntry > tyEntry)
		{
			if (dxEntry > 0.0f)
			{
				manifold.collisionNormal = Vec2(1.0f, 0.0f); // hướng từ phải sang trái
				setCollisionNormal(manifold);
			}
			else
			{
				manifold.collisionNormal = Vec2(-1.0f, 0.0f); // hướng từ trái sang phải
				setCollisionNormal(manifold);
			}
		}
		else
		{
			if (dyEntry > 0.0f)
			{
				manifold.collisionNormal = Vec2(0.0f, 1.0f); // hướng từ trên xuống
				setCollisionNormal(manifold);
			}
			else
			{
				manifold.collisionNormal = Vec2(0.0f, -1.0f); // hướng từ dưới lên
				setCollisionNormal(manifold);
			}
		}

		return entryTime;		// trả về thời gian sẽ xảy ra va chạm
	}

}

Vec2 PhysicsManager::getCollisionNormal() const
{
	return _collisionNormal;
}

void PhysicsManager::setCollisionNormal(const Manifold manifold)
{
	_collisionNormal = manifold.collisionNormal;
}


void PhysicsManager::resolveCollision(Manifold &manifold) const
{
	// Calculate relative velocity
	const auto relativeVelocity = manifold.rigid2->getVelocity() - manifold.rigid1->getVelocity();

	// Calculate
	const auto velocityAlongNormal = dotProduct(relativeVelocity, manifold.collisionNormal);

	if (velocityAlongNormal > 0)
		return;

	const auto restitution = min(manifold.rigid2->getRestitution(), manifold.rigid1->getRestitution());

	// Calculate impulse scalar (hệ số xung lực)
	auto j = -(1 + restitution)*velocityAlongNormal;

	// j /= 1 / A.mass + 1 / B.mass
	// mass = density*squared
	// squared = width*height
	const auto massA = manifold.rigid1->getDensity() * manifold.rigid1->getSize().getWidth()*manifold.rigid1->getSize().getHeight();
	const auto massB = manifold.rigid2->getDensity() * manifold.rigid2->getSize().getWidth()*manifold.rigid2->getSize().getHeight();
	j /= 1 / (massA)+1 / (massB);

	// Apply impulse
	const auto impulse = manifold.collisionNormal * j;

	// Calculate sum of mass
	const auto massSum = massA + massB;

	// ratio: tỉ lệ khối lượng
	auto ratio = massA / massSum;

	//const auto collisiontime = sweptAABB(manifold.rigid1, manifold.rigid2, manifold);

	if (manifold.rigid1->getBodyType() == DYNAMIC)
	{
		manifold.rigid1->setVelocity(manifold.rigid1->getVelocity() - impulse / massA);
		//manifold.rigid1->setPosition(Vec2(manifold.rigid1->getPosition() + manifold.rigid1->getVelocity() * collisiontime));
	}

	ratio = massB / massSum;
	if (manifold.rigid2->getBodyType() == DYNAMIC)
	{
		//manifold.rigid1->setPosition(Vec2(manifold.rigid1->getPosition() + manifold.rigid1->getVelocity() * collisiontime));
		manifold.rigid2->setVelocity(manifold.rigid2->getVelocity() + impulse / massB);
	}

	positionalCorrection(manifold);
}




float PhysicsManager::dotProduct(const Vec2& v1, const Vec2& v2)
{
	return v1.getX() * v2.getX() + v1.getY() * v2.getY();
}




void PhysicsManager::positionalCorrection(const Manifold& manifold) const
{
	const auto massA = manifold.rigid1->getDensity() * manifold.rigid1->getSize().getWidth()*manifold.rigid1->getSize().getHeight();
	const auto massB = manifold.rigid2->getDensity() * manifold.rigid2->getSize().getWidth()*manifold.rigid2->getSize().getHeight();

	const auto inverseMassA = 1 / massA;
	const auto inverseMassB = 1 / massB;

	const float percent = 0.2; // usually 20% to 80%

	const float slop = 0.01; // usually 0.01 to 0.1

	const auto correction = manifold.collisionNormal * percent* max(manifold.penetration - slop, 0.0f) / (inverseMassA + inverseMassB);

	if (manifold.rigid1->getBodyType() == DYNAMIC)
	{
		manifold.rigid1->setPosition(Vec2(manifold.rigid1->getPosition() - correction * inverseMassA));
	}
	if (manifold.rigid2->getBodyType() == DYNAMIC)
	{
		manifold.rigid2->setPosition(Vec2(manifold.rigid2->getPosition() + correction * inverseMassB));
	}

}




PhysicsManager* PhysicsManager::getIntance()
{
	if (_instance == nullptr)
	{
		_instance = new PhysicsManager();
	}

	return _instance;
}




bool PhysicsManager::AABBvAABB(RigidBody* a, RigidBody *b, Manifold& manifold)
{
	manifold.rigid1 = a;
	manifold.rigid2 = b;

	// Vector from a to b
	auto vecAtoB = b->getPosition() - a->getPosition();

	// Tính phân nửa chiều rộng (x) của mỗi body
	auto a_extent = a->getSize().getWidth() / 2;
	auto b_extent = b->getSize().getWidth() / 2;

	// Tính phần đè lên nhau theo trục x
	const auto x_overlap = a_extent + b_extent - abs(vecAtoB.getX());

	if (x_overlap > 0)
	{
		// Tính phân nửa chiều dài (y) của mỗi body
		a_extent = a->getSize().getHeight() / 2;
		b_extent = b->getSize().getHeight() / 2;

		// Tính phần đè lên nhau theo trục y
		const auto y_overlap = a_extent + b_extent - abs(vecAtoB.getY());

		if (y_overlap > 0)
		{
			// Tính toán xem phần đè lên nhau nào ít hơn thì hướng va chạm sẽ theo chiều đó
			if (x_overlap < y_overlap)
			{
				if (vecAtoB.getX() < 0)
				{
					manifold.collisionNormal = Vec2(-1, 0);
					setCollisionNormal(manifold);
				}
				else
				{
					manifold.collisionNormal = Vec2(1, 0);
					setCollisionNormal(manifold);
				}
					
				manifold.penetration = x_overlap;
				return true;
			}
			else
			{
				if (vecAtoB.getY() < 0)
				{
					manifold.collisionNormal = Vec2(0, -1);
					setCollisionNormal(manifold);
				}
				else
				{
					manifold.collisionNormal = Vec2(0, 1);
					setCollisionNormal(manifold);
				}

				manifold.penetration = y_overlap;
				return true;
			}
		}
	}

	return false;
}
