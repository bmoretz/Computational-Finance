#pragma once

template <class Res>
class MathFunction
{
public:
	MathFunction() = default;
	MathFunction( const MathFunction &p ) = default;
	MathFunction& operator=( const MathFunction &p ) = default;

	virtual ~MathFunction() = default;
	virtual Res operator()( Res value ) = 0;
	virtual Res operator()( Res x, Res y ) = 0;
};