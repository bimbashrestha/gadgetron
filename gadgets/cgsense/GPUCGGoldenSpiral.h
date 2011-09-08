#ifndef GPUCGGOLDENSPIRALGADGET_H
#define GPUCGGOLDENSPIRALGADGET_H
#pragma once

#include "GPUCGGadget.h"

#include <tinyxml.h>

class EXPORTGADGETSCGSENSE GPUCGGoldenSpiralGadget : public GPUCGGadget
{

 public:
  GADGET_DECLARE(GPUCGGoldenSpiralGadget)

  GPUCGGoldenSpiralGadget();
  virtual ~GPUCGGoldenSpiralGadget();

 protected:
  virtual int set_base_parameters(TiXmlNode* node);
  virtual int process_config(ACE_Message_Block* mb);

  virtual int copy_samples_for_profile(float* host_base_ptr,
				       std::complex<float>* data_base_ptr,
				       int profile_no,
				       int channel_no);

  virtual int calculate_trajectory();
  virtual int calculate_density_compensation();


  int Interleaves_;
  int ADCsPerInterleave_;
  int SamplesPerADC_;
  int SamplesToSkipStart_;
  int SamplesToSkipEnd_; 
  int SamplingTime_ns_;
  int Reordering_;
  double MaxGradient_Gcm_;
  double MaxSlewRate_Gcms_;
  double krmax_cm_;
  double FOVCoeff_1_;

  int     host_allocated_traj_samples_;
  float2* host_trajectory_ptr_;
  float*  host_density_weight_ptr_;
  int allocated_dev_traj_samples_;

};

#endif //GPUCGGOLDENSPIRALGADGET_H