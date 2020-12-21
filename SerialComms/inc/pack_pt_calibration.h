/// BEGIN AUTOGENERATED SECTION - MODIFICATIONS TO THIS CODE WILL BE OVERWRITTEN

/// pack_pt_calibration.h
/// Autogenerated by pt_calibration_generator.py on Mon Dec 21 15:33:08 2020

struct Pt_calib {
	double slope;
	double offset;
};

extern void pt_calibration_data(struct Pt_calib* data);

extern void update_temp(struct Pt_calib *temp, double slope, double offset);