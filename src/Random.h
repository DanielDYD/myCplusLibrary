// Random data generator

# ifndef H_RANDOM
# define H_RANDOM

# include <complex>
using namespace std;
//Random number generator
class Random
{
private:
//Modular Arithmetic Generator
	int StateS;
	static const int A = 48271;
	static const int M = 2147483647;
	static const int Q = 44488;
	static const int R = 3399;
//Wichmann/Hill Generator
	int	StateX;
	int	StateY;
	int StateZ;
	static const int A1 = 171;
	static const int A2 = 172;
	static const int A3 = 170;
	static const int M1 = 30269;
	static const int M2 = 30307;
	static const int M3 = 30323;
//Box-Muller Method
	static const double pi2 ;


public:
//Modular Arithmetic Generator
	void	SetState( int s );
	void	ReadState( int *s );
	void	IntNextSate( int *s );
	int		RandomInt( );
//Wichmann/Hill Generator
	void	SetState( int x, int y, int z );
	void	ReadState( int *x, int *y, int *z );
	void	DoubleNextState( int *x, int *y, int *z );
	double	RandomDouble( );

//Both Wichmann/Hill and Modular Arithmetic Generator
	void	SetState( int s, int x, int y, int z );
	void	ReadState( int *s, int *x, int *y, int *z );
//Box-Muller Method
	double	RealNoise( double sigma );
	complex<double>	ComplexNoise( double sigma );

};

# endif
