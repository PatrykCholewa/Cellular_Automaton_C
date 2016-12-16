function dY(double t, double *Y){
	double mb = 0.2;
	double mw = 2.5;
	double A = 0.0109;
	double h = 50;
	double cb = 0.22; 
	double cw = 0.07;
	double Tb = Y[0];
	double Tw = Y[1];

	double dY[2];
	dY[0] = (Tw - Tb) * h * A / (mb*cb);
        dY[1]   (Tb - Tw) * h * A / (mw*cw);   

	return dY;
}
