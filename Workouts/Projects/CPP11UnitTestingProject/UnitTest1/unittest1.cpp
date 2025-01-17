#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\CPP11\Testing.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Testing;

namespace UnitTestingExample
{		
	TEST_CLASS(UnitTestForMyProjectClass)
	{
	public:
		
		TEST_METHOD(Multiply2Numbers)
		{
			MyProject abc;
			Assert::AreEqual(6, abc.Multiply(2, 3));
		}

		TEST_METHOD(RangeOfSquareRoots)
		{
			MyProject abc;
			for (double v = 1e-6; v < 1e6; v = v * 3.2)
			{
				double actual = abc.SquareRoot(v*v);
				Assert::AreEqual(
					// Expected value:
					v,
					// Actual value:
					abc.SquareRoot(v*v),
					// Tolerance:
					0.01,
					// Message:
					L"Basic test failed",
					// Line number - used if there is no PDB file:
					LINE_INFO());
			}
		}

		TEST_METHOD(DoubleAreEqual)
		{
			MyProject abc;
			Assert::AreEqual(1.1f, abc.AddDouble(1.05f, 0.05f), 0.1f, L"Double comparison failed", LINE_INFO());
		}
	};
}