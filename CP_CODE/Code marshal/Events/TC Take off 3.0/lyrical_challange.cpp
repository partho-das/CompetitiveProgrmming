double d1 = 1 / e;
double d = fmod(d1, pbi);
double massage = 9;
double c = pow(massage, 3);
double m = pow(c, d);
c = fmod(c, n);

m = fmod(m, n);


cout << "Original Massage: " << massage;