#include "Speed.h"
#include <iostream>
#include <stdexcept>

Speed::Speed() noexcept
{
	Speed::speed = 0.0;
	Speed::unit = "m/s";
	Speed::converter = 1.0;
}

Speed::Speed(double speed, std::string unit, double converter) 
{
	if (converter <= 0.0)
	{
		throw std::range_error("Invalid converter.");
	}
	if (speed < 0)
	{
		throw std::range_error("Invalid speed");
	}
	Speed::speed = speed;
	Speed::unit = unit;
	Speed::converter = converter;

}


void Speed::setSpeed(double const speed) noexcept
{
	this->speed = speed;
}

double Speed::getSpeed() const noexcept
{
	return speed;
}

double Speed::getConverter() const noexcept
{
	return converter;
}


std::string Speed::getUnit() const noexcept
{
	return unit;
}

double Speed::getSpeedSI() const noexcept
{
	return speed * converter;
}

Speed Speed::operator+(Speed const& s) const noexcept
{
	Speed result(*this);
	result += s;
	return result;
}

Speed Speed::operator-(Speed const & s) const noexcept
{
	Speed result(*this);
	result -= s;
	return result;
}

void Speed::operator+=(Speed const& s) noexcept
{

	speed += s.getSpeedSI() / converter;

}

void Speed::operator-=(Speed const& s) noexcept
{
	speed -= s.getSpeedSI() / converter;

}

bool Speed::operator==(Speed const& s) const noexcept
{

	return getSpeedSI() == s.getSpeedSI();

}

bool Speed::operator!=(Speed const& s) const noexcept
{
	return !(*this == s);
}
