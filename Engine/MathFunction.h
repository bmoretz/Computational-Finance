#pragma once

template <class Res>
class MathFunction
{
public:
	MathFunction();
	virtual ~MathFunction();
	virtual Res operator() ( Res value ) = 0;
};

template <class Res>
MathFunction<Res>::MathFunction()
{
}

template <class Res>
MathFunction<Res>::~MathFunction()
{
}
