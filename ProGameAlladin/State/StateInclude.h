#ifndef __STATEINCLUDE_H__

#define __STATEINCLUDE_H__

#include "../Framework/definitions.h"
#include "../Framework/Input.h"
#include "../Framework/Node.h"
#include "../Aladdin.h"

#include "State.h"

											// STATE
#include "Idle.h"							// 1			
#include "Run.h"							// 2
#include "Throw.h"							// 3
#include "Slash.h"							// 4
#include "Jump.h"							// 5
#include "Climb.h"							// 6
#include "RunAndJump.h"						// 7
#include "HeadUp.h"							// 8
#include "JumpAndSlash.h"					// 9
#include "JumpAndThrow.h"					// 10
#include "Push.h"							// 11
#include "HeadUpAndSlash.h"					// 12
#include "IdleToSit.h"							// 13
#include "SitAndThrow.h"					// 14
#include "SitAndSlash.h"					// 15					
#include "RunAndSlash.h"					// 16
#include "Fall.h"							// 17
#include "Brake.h"							// 18
#include "Wing.h"							// 19
#include "IdleWhenWing.h"					// 20
#include "ThrowWhenWing.h"					// 21
#include "SlashWhenWing.h"					// 22
#include "JumpWhileClimb.h"					// 23
#include "BeingAttacked.h"					// 24
#include "BeingAttackedAndDie.h"			// 25
#include "BeingRescued.h"					// 26
#include "RunAndThrow.h"					// 27
#include "IdleWhenClimb.h"					// 28
#include "ThrowWhenClimb.h"					// 29
#include "SlashWhenClimb.h"					// 30

#endif __STATEINCLUDE_H__
