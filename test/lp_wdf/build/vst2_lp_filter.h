class lp_filter
{
public:
	void setSampleRate(float sampleRate);
	void reset();
	void process(float *x, float *y__out__, int nSamples);

	float getcutoff();
	void setcutoff(float value);

private:

	
	float Rr_5;
	float lp_filter__extra__1;
	float __delayed__2;
	
	
	float cutoff = 0;

	
	float cutoff_z1;
	char cutoff_CHANGED;
	

	float fs;
	char firstRun;

};
