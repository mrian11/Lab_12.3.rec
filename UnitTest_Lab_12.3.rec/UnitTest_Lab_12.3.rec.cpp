#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12.3.rec/LAB.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab123rec
{
	TEST_CLASS(UnitTestLab123rec)
	{
	public:

		TEST_METHOD(TestInsertBeforeFirst)
		{
			Elem* first = nullptr;
			Elem* last = nullptr;

			
			enqueue(first, last, 10);
			enqueue(first, last, 20);

		
			insertBeforeFirst(first, 10, 5);

		
			Assert::AreEqual(first->info, 5);

			Assert::AreEqual(first->next->info, 10);
		}
	};
}
