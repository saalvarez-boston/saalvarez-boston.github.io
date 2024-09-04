// File> MysteryAlgorithms.cxx, by Sergio A. Alvarez
// Implementation file for the MysteryAlgorithms class

#include <iostream>
#include "MysteryAlgorithms.h"
using namespace std;


		void MysteryAlgorithms::alg1(double n) {
			for (double k=n; k>0; k--)
				for (double j=n; j>0; j--);
		}

		void MysteryAlgorithms::alg2(double n) {
			double m;
			for (long k=10000; k>0; k--) {
				m = n;
				while (m > 1) m/=2;
			}
		}

		void MysteryAlgorithms::alg3(double n) {
			double m;
			for (double k=n; k>0; k--)
				for (long k=1; k>0; k--) {
					m = n;
					while (m > 1) m/=2;
				}
		}

		void MysteryAlgorithms::alg4(double n) {
			for (long k=10000; k>0; k--);
			for (double k=n; k>0; k--);
		}

		void MysteryAlgorithms::alg5(double n) {
			for (double k=n; k>0; k--)
				for (double j=n; j>0; j--)
					for (double i=n; i>0; i--);
		}

