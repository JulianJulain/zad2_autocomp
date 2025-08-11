#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Queue.hpp"
#include <string>

using namespace std;

TEST_CASE("Kolejka jest pusta") {
	Queue<int>kolejka;
	CHECK(kolejka.isEmpty() == true);
	CHECK(kolejka.size() == 0);
}
TEST_CASE("Dodawanie do kolejki") {
	Queue<int>kolejka;
	kolejka.enqueue(1);
	kolejka.enqueue(2);
	kolejka.enqueue(3);
	CHECK(kolejka.isEmpty() == false);
	CHECK(kolejka.size() == 3);
}
TEST_CASE("Usuwanie z kolejki") {
	Queue<int>kolejka;
	kolejka.enqueue(1);
	kolejka.enqueue(2);
	kolejka.enqueue(3);
	CHECK(kolejka.dequeue() == 1);
	CHECK(kolejka.size() == 2);
	CHECK(kolejka.dequeue() == 2);
	CHECK(kolejka.size() == 1);
	CHECK(kolejka.dequeue() == 3);
	CHECK(kolejka.isEmpty() == true);
}

TEST_CASE("Próba odczytu z pustej kolejki") {
	Queue<int>kolejka;
	CHECK_THROWS_AS(kolejka.dequeue(), out_of_range);

}

TEST_CASE("Czy klient jest na pocz¹tku kolejki") {
	Queue<string>kolejka;
	kolejka.enqueue("Klient_nr_1");
	CHECK(kolejka.front() == "Klient_nr_1");
	kolejka.enqueue("Klient_nr_2");
	CHECK(kolejka.front() == "Klient_nr_1");
	kolejka.dequeue();
	CHECK(kolejka.front() == "Klient_nr_2");
	CHECK(kolejka.size() == 1);
	CHECK(kolejka.isEmpty() == false);
}

TEST_CASE("Usuwanie z pustej kolejki") {
	Queue<int>kolejka;
	CHECK_THROWS_AS(kolejka.front(), out_of_range);
}
TEST_CASE("Obs³uga klienta") {
	Queue<string>kolejka;
	kolejka.enqueue("Klient_1");
	kolejka.enqueue("Klient_2");

	string pierwszy_klient = kolejka.dequeue();
	CHECK(pierwszy_klient == "Klient_1");
	CHECK(kolejka.size() == 1);
	CHECK(kolejka.front() == "Klient_2");
}
TEST_CASE("Czy wszystko dzia³a") {
	Queue<int>kolejka;
	for (int i = 0; i < 10; i++) {
		kolejka.enqueue(i);
	}
	CHECK(kolejka.size() == 10);
	for (int i = 0; i < 5; i++) {
		CHECK(kolejka.dequeue() == i);

	}
	CHECK(kolejka.size() == 5);
}
TEST_CASE("Pusta po usuniêciu wszystkiego") {
	Queue<int>kolejka;
	kolejka.enqueue(1);
	kolejka.dequeue();
	CHECK(kolejka.isEmpty());
}