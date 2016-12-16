int main(int argc, char **argv){
	/* 
	 *dodac aloka dla 2 wymiaru
	*/
	double *Y[2];
	alloc(Y[0],0);
	alloc(Y[1],0);
	Y[0][0] = 1200;
	Y[1][0] = 65;
	double h = 0.01;
	double t = 0;
	double t_end = 2;
	int i = 0;
	char ok = 0;
	int n = 1;
	while (t < t_end){
		alloc(Y[0],n);
		alloc(Y[1],n);
		Y[0][n] = Y[0][n - 1] + h * dY(t, Y, n - 1);
		/* 
		 * dY dodać trzecią zmienną 
		 */
		Y[1][n] = Y[1][n - 1] + h * dY(t, Y, n - 1);
		n = n + 1;
		t = t + h;

		/*
		 * Tb = Y[1,i] ???
		 */
		if (Tb <= 200 && ok == 0){
			ok = 1;
			/*
			 * display[t]; ???
			 */
		}
	}
	/* 
	 * ...
	 */
	return 0;
} 
