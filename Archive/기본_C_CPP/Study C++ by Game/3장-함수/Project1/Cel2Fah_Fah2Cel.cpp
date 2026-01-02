double Cel2Fah(double cel)
{
	double fah = 32 + 180.0 / 100.0 * cel;
	return fah;
}

double Fah2Cel(double fah)
{
	double cel = (fah - 32)*100.0/180.0;
	return cel;
}