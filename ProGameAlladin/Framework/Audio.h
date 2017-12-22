#ifndef __AUDIO_H__
#define __AUDIO_H__

#include "Sound.h"
#include "dxaudio.h"


NS_JK_BEGIN

//ALA_CLASS_HEADER_2(Audio, ala::Initializable, ala::Releasable)
  // =====================================================
  // Basics
  // =====================================================
	class Audio
{
  //friend class Application;

private:
  static Audio* __instance;
  //Logger _logger;

public:
  Audio();

  virtual ~Audio();
  HWND _hWnd;

  static Audio* get();

  void load( Sound* sound );

  void play( Sound* sound, bool loop );

  void stop( Sound* sound );

public:
	void initialize(); //override;

  void release() ;

 // void onBackgroundToForeground();

  // =====================================================
  // Platform specific
  // =====================================================
private:

  CSoundManager* _directXSound;

  void initDirectXSound();

  void releaseDirectXSound();

};

NS_JK_END
#endif //!__AUDIO_H__
