#include "SimplestEffect.h"
#include "IPlug_include_in_plug_src.h"


SimplestEffect::SimplestEffect(const InstanceInfo& info)
: Plugin(info, MakeConfig(kNumParams, kNumPresets))
{
}

#if IPLUG_DSP
void SimplestEffect::ProcessBlock(sample** inputs, sample** outputs, int nFrames)
{ 
  const int nChans = NOutChansConnected();
  const double gain = 0.5;
  
  for (int s = 0; s < nFrames; s++) {
    for (int c = 0; c < nChans; c++) {
      outputs[c][s] = inputs[c][s] * gain;
    }
  }
}
#endif
