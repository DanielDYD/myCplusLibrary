// The definitions of functions in Random class.

# include "Random.h"

const double	Random::pi2 = 6.2831853071795864;
//-------------------------------Random number generator--------------------------------------
//Modular Arithmetic Generator
void Random::SetState( int s )
{
	StateS = s;
}

void Random::ReadState( int *s )
{
	*s = StateS;
}

void Random::IntNextSate( int *s )
{
	int tmpState = A * ( *s % Q ) - R * ( *s / Q );

	if( tmpState >= 0 )
		*s = tmpState;
	else
		*s = tmpState + M;
}

int Random::RandomInt( )
{
	Random::IntNextSate( &StateS );
	return StateS;
}
//Wichmann/Hill Generator
void Random::SetState( int x, int y, int z )
{
	StateX = x;
	StateY = y;
	StateZ = z;
}
void Random::ReadState( int *x, int *y, int *z )
{
	*x = StateX;
	*y = StateY;
	*z = StateZ;
}
void Random::DoubleNextState( int *x, int *y, int *z )
{
	*x = ( *x * A1 ) % M1;
	*y = ( *y * A2 ) % M2;
	*z = ( *z * A3 ) % M3;
}
double Random::RandomDouble( )
{
	double tmp;

	Random::DoubleNextState( &StateX, &StateY, &StateZ );
	tmp = (double) StateX / (double) M1 + (double) StateY / (double) M2 + (double) StateZ / (double) M3;
	return tmp - (double) ( (int) tmp );//mod 1 operatoion
}
//Both Wichmann/Hill and Modular Arithmetic Generator
void Random::SetState( int s, int x, int y, int z )
{
	StateS = s;
	StateX = x;
	StateY = y;
	StateZ = z;
}
void Random::ReadState( int *s, int *x, int *y, int *z )
{
	*s = StateS;
	*x = StateX;
	*y = StateY;
	*z = StateZ;
}
//Box-Muller Method
double Random::RealNoise( double sigma )
{
	double amp = sigma * sqrt( -2.0 * log( Random::RandomDouble( ) ) );
	double angle = pi2 * Random::RandomDouble( );

	return amp * cos( angle );
}

complex<double> Random::ComplexNoise( double sigma )
{
	complex<double> symbol;
	double angle = pi2 * Random::RandomDouble( );
	double amp = sigma * sqrt( -2.0 * log( Random::RandomDouble( ) ) );

	symbol = complex<double>(amp * cos( angle ), amp * sin( angle ));
	return symbol;
}
