#pragma once
#include <string>
class Speed
{
private:
	double speed;
	std::string unit;
	double converter;
public:
	Speed() noexcept;
	Speed(double speed, std::string unit, double converter);
	void setSpeed(double speed) noexcept;
	double getSpeed() const noexcept;
	std::string getUnit() const noexcept;
	double getConverter() const noexcept;
	double getSpeedSI() const noexcept;

	Speed operator+(Speed const& c) const noexcept;
	Speed operator-(Speed const& c) const noexcept;
	void operator+=(Speed const& c) noexcept;
	void operator-=(Speed const& c) noexcept;

	bool operator==(Speed const& c) const noexcept;
	bool operator!=(Speed const& c) const noexcept;
};

