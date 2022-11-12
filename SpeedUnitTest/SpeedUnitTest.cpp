#include "CppUnitTest.h"
#include "../SpeedLib/Speed.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SpeedUnitTest
{
	TEST_CLASS(SpeedUnitTest)
	{
	public:
		
		TEST_METHOD(initiateNoParameters)
		{
			Speed s;
			std::string u = "m/s";
			Assert::AreEqual(0.0, s.getSpeed(), 0.01);
			Assert::AreEqual(u, s.getUnit());
			Assert::AreEqual(1.0, s.getConverter(), 0.01);
		}

		TEST_METHOD(initiateWithParameters)
		{
			Speed s(20.0, "k/h", 3.0);
			std::string u = "k/h";
			Assert::AreEqual(20.0, s.getSpeed(), 0.01);
			Assert::AreEqual(u, s.getUnit());
			Assert::AreEqual(3.0, s.getConverter(), 0.01);
		}
		TEST_METHOD(initiateWithParametersExceptionConverter)
		{
			Assert::ExpectException<std::range_error>([]() {Speed s(20, "m/s", 0.0); });
		}

		TEST_METHOD(initiateWithParametersExceptionSpeed)
		{
			Assert::ExpectException<std::range_error>([]() {Speed s(-10, "m/s", 1.0); });
		}
		TEST_METHOD(setSpeedTo20)
		{
			Speed s;
			s.setSpeed(20.0);
			Assert::AreEqual(20, s.getSpeed(), 0.01);
		}

		TEST_METHOD(getSpeed)
		{
			Speed s(20.0, "m/s", 3.4);
			Assert::AreEqual(20.0, s.getSpeed(), 0.01);
		}
		TEST_METHOD(getUnits)
		{
			Speed s(3.0, "k/h", 3.0);
			std::string	u = "m/s";
			Assert::AreNotEqual(u, s.getUnit());
		}
		TEST_METHOD(getConverter)
		{
			Speed s;
			Assert::AreEqual(1.0, s.getConverter(), 0.01);
		}
		TEST_METHOD(getspeedSI)
		{
			Speed s(12.0, "m/s", 4.0);
			Assert::AreEqual(48.0, s.getSpeedSI(), 0.01);
		}
		TEST_METHOD(operatorPlusAdd20To30)
		{
			Speed s1(20.0, "m/s", 3.0);
			Speed s2(30.0, "m/s", 3.0);
			Speed result;
			result = s1 + s2;
			Assert::AreEqual(50.0, result.getSpeed(), 0.01);
		}
		TEST_METHOD(operatorPlusAdddefaultTo10)
		{
			Speed s1;
			Speed s2(10.0, "m/s", 1.0);
			Speed result;
			result = s1 + s2;
			Assert::AreEqual(10.0, result.getSpeed(), 0.01);

		}
		TEST_METHOD(operatorPlusEqualdefaultTo30)
		{
			Speed s1;
			Speed s2(10.0, "m/s", 1.0);
			 s1 += s2;
			Assert::AreEqual(10.0, s1.getSpeed(), 0.01);
		}
		TEST_METHOD(operatorPlusEqual10And10)
		{
			Speed s1(20.0, "m/s", 3.0);
			Speed s2(30.0, "m/s", 3.0);
			s1 += s2;
			Assert::AreEqual(50.0, s1.getSpeed(), 0.01);
		}
		TEST_METHOD(operatorEqualCompareDefaultandSet)
		{
			Speed s1;
			Speed s2(30.0, "m/s", 1.0);
			Assert::IsFalse(s1 == s2);
		}
		TEST_METHOD(operatorEqualCompareMPSAndKPH)
		{
			Speed s1(108.0, "m/s",1.0);
			Speed s2(30.0, "k/h", 3.6);
			Assert::IsTrue(s1 == s2);
		}
		TEST_METHOD(operatorminus50and10)
		{
			Speed s1(50.0, "m/s", 1.0);
			Speed s2(10.0, "m/s", 1.0);
			Speed result;
			result = s1 - s2;
			Assert::AreEqual(40.0, result.getSpeed(), 0.01);
		}
		TEST_METHOD(operatorminusdefaultand30)
		{
			Speed s1;
			Speed s2(30.0, "m/s", 1.0);
			Speed result;
			result = s1 - s2;
			Assert::AreEqual(-30.0, result.getSpeed(), 0.01);
		}
		TEST_METHOD(operatorNotEqualdefaultAndSet)
		{
			Speed s1(200.0, "m/s", 1.0);
			Speed s2(30.0, "m/s", 1.0);
			Assert::IsTrue(s1 != s2);
		}
		TEST_METHOD(operatorNotEqual20And20)
		{
			Speed s1(20.0, "m/s", 1.0);
			Speed s2(20.0, "m/s", 1.0);
			Assert::IsFalse(s1 != s2);
		}
		TEST_METHOD(operatorNotEqualMPSAndKPH)
		{
			Speed s1(200.0, "m/s", 1.0);
			Speed s2(30.0, "k/h", 3.6);
			Assert::IsTrue(s1 != s2);
		}

	};
}
