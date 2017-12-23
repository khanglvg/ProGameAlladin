#ifndef __SOUND_H__
#define __SOUND_H__

#include "definitions.h"
#include "dxaudio.h"

NS_JK_BEGIN
class Sound
{
	
	//ALA_CLASS_HEADER_2(Sound, ala::Initializable, ala::Releasable)
	private:
	  std::string _sourceFile;

	public:
	  Sound(const std::string& sourceFile);

	  virtual ~Sound();

public:
	  void initialize() ;

	  void release() ;

	  const std::string& getSourceFile() const;

	  // ===================================================
	  // Platform specific
	  // ===================================================
	private:
	  CSound* _cSound;

	public:
	  CSound* getCSound() const;

	  void setCSound(CSound* cSound);

	  bool isPlaying() const;

	private:
	  void initCSound();

	  void releaseCSound();
};
NS_JK_END


#endif //!__ALADDIN_AUDIO_SOUND_H__
