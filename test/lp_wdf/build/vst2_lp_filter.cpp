#include "vst2_lp_filter.h"


static const float C = 0.000001f;
static const float C_3 = C;
static const float lp_filter__extra__0 = (2.f * 3.141592653589793f);
static const float al_5 = 0.f;


void lp_filter::reset()
{
	firstRun = 1;
}

void lp_filter::setSampleRate(float sampleRate)
{
	fs = sampleRate;
	Rr_5 = (0.5f / (C_3 * fs));
	
}

void lp_filter::process(float *x, float *y__out__, int nSamples)
{
	if (firstRun) {
		cutoff_CHANGED = 1;
	}
	else {
		cutoff_CHANGED = cutoff != cutoff_z1;
	}
	
	if (cutoff_CHANGED) {
		lp_filter__extra__1 = (Rr_5 / ((1.f / ((lp_filter__extra__0 * ((0.1f + (0.3f * cutoff)) * fs)) * C)) + Rr_5));
	}
	
	cutoff_CHANGED = 0;

	if (firstRun) {
		
		__delayed__2 = 0.f;
	}

	for (int i = 0; i < nSamples; i++) {
		
		const float bC = __delayed__2;
		const float ar_5 = bC;
		const float aC = (ar_5 - (lp_filter__extra__1 * ((al_5 + ar_5) + ((2.f * x[i]) - -((al_5 + ar_5))))));
		const float y = (0.5f * (aC + bC));
		
		__delayed__2 = aC;
		
		
		y__out__[i] = y;
	}

	
	cutoff_z1 = cutoff;
	firstRun = 0;
}


float lp_filter::getcutoff() {
	return cutoff;
}
void lp_filter::setcutoff(float value) {
	cutoff = value;
}
