#include "Audio.h"

US_NS_JK

//ALA_CLASS_SOURCE_2(ala::Audio, ala::Initializable, ala::Releasable)

Audio* Audio::__instance( NULL );

Audio::Audio() :
 // _logger( "ala::Audio" ),
  _hWnd( 0 ),
  _directXSound( 0 ) {
  //ALA_ASSERT((!isInitialized()) && (!isInitializing()) && (!isReleased()) && (!isReleasing()));
  //_logger.info( "Created" );
}

Audio::~Audio() {
  //if ( isInitialized() ) {
  //  ALA_ASSERT(isReleased());
  //}
  //_logger.info( "Released" );
}

Audio* Audio::get() {
  if ( __instance == NULL ) {
    __instance = new Audio();
  }
  return __instance;
}

void Audio::load( Sound* sound ) {
 // ALA_ASSERT(sound != NULL);

  HRESULT result;

  CSound* cSound = 0;

  char srcFile[256];
  std::copy( sound->getSourceFile().cbegin(), sound->getSourceFile().cend(), srcFile );
  srcFile[sound->getSourceFile().length()] = '\0';

  result = _directXSound->Create( &cSound, srcFile );
// ALA_ASSERT(result == DS_OK);

  sound->setCSound( cSound );
}

void Audio::play( Sound* sound, bool loop ) {
  if ( sound == NULL ) return;
  if ( !sound->getCSound() ) return;

  if ( loop ) {
    sound->getCSound()->Play( 0, DSBPLAY_LOOPING );
  }
  else {
    sound->getCSound()->Play();
  }
}

void Audio::stop( Sound* sound ) {
  if ( sound == NULL ) return;
  if ( !sound->getCSound() ) return;

  if ( sound->getCSound()->IsSoundPlaying() ) {
    sound->getCSound()->Stop();
  }
}

void Audio::initialize() {
 // ALA_ASSERT((!isInitialized()) && (!isInitializing()));

 // setToInitializing();

  initDirectXSound();

  //setToInitialized();
}

void Audio::release() {
	//  ALA_ASSERT(isInitialized() && (!isReleased()) && (!isReleasing()));
	//
	//  setToReleasing();
	//
	releaseDirectXSound();
	//
	//  setToReleased();

	  // destroy
	  delete this;
}

//void Audio::onBackgroundToForeground() {}

void Audio::initDirectXSound() {
  HRESULT result;

  _directXSound = new CSoundManager();
  result = _directXSound->Initialize( _hWnd, DSSCL_PRIORITY );
  //ALA_ASSERT(result == DS_OK);

  result = _directXSound->SetPrimaryBufferFormat( 2, 22050, 16 );
 // ALA_ASSERT(result == DS_OK);

  //_logger.info( "Created DirectX Sound" );
}

void Audio::releaseDirectXSound() {
  if ( _directXSound ) 
  {
    delete _directXSound;
    _directXSound = nullptr;

   // _logger.info( "Released DirectX Sound" );
  }
}

