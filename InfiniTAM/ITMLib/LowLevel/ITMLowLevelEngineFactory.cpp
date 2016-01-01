// Copyright 2014-2015 Isis Innovation Limited and the authors of InfiniTAM

#include "ITMLowLevelEngineFactory.h"

#include "CPU/ITMLowLevelEngine_CPU.h"
#ifndef COMPILE_WITHOUT_CUDA
#include "CUDA/ITMLowLevelEngine_CUDA.h"
#endif
#ifdef COMPILE_WITH_METAL
#include "Metal/ITMLowLevelEngine_Metal.h"
#endif

namespace ITMLib
{

//#################### PUBLIC STATIC MEMBER FUNCTIONS ####################

ITMLowLevelEngine *ITMLowLevelEngineFactory::MakeLowLevelEngine(ITMLibSettings::DeviceType deviceType)
{
  ITMLowLevelEngine *lowLevelEngine = NULL;

  switch(deviceType)
  {
    case ITMLibSettings::DEVICE_CPU:
      lowLevelEngine = new ITMLowLevelEngine_CPU;
      break;
    case ITMLibSettings::DEVICE_CUDA:
#ifndef COMPILE_WITHOUT_CUDA
      lowLevelEngine = new ITMLowLevelEngine_CUDA;
#endif
      break;
    case ITMLibSettings::DEVICE_METAL:
#ifdef COMPILE_WITH_METAL
      lowLevelEngine = new ITMLowLevelEngine_Metal;
#endif
      break;
  }

  return lowLevelEngine;
}

}
