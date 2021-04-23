#include <global.hh>
#include <timing.hpp> 

/////////////////////////////////////////////////////////////////////////////////
//   Usage:
//           ./program_name -nt T -nx S
//           T:   number of iterations to run for (default = 100)
//           S:   problem size (default = 15000)
//
//   Description:
//           Computes a[0:nx-1] = a[0:nx-1]*b[0:nx-1] + c[0:nx-1] T times, for array length nx
//           Reports time
//
/////////////////////////////////////////////////////////////////////////////////


int main(int argc, char** argv) {
    uint64_t niter=10000;                                   // 1
    uint64_t nx=150000;                                     // 1
	
    std::string mystr;
    double *a, *b, *c;                                      // 3

    ///////////////////////////////////////
    //  Read command-line parameters -nt
    for (size_t i=0; i < argc; i++) {                       // n
        mystr=argv[i];                                      // n
        if (mystr == "-nt"){                                // n
            niter=atoi(argv[i+1]);                          // n
        }
		if (mystr == "-nx"){                                // n
			nx=atoi(argv[i+1]);                             // n
		}
    }

    std::cout << "Looping " << niter << " times."   << std::endl;
	std::cout << "Problem size nx is: " << nx << std::endl;

    //////////////////////////////////////////
    // Initialize
    a = new double[nx];                                     // 1
	b = new double[nx];                                     // 1
	c = new double[nx];                                     // 1
    for (size_t i = 0; i < nx; i++) {                       // n
      a[i] = 1.0;                                           // n
	  b[i] = 2.0;                                           // n
	  c[i] = 5.0;                                           // n
    }


    /////////////////////////////
    //  Compute Loop
	//  Determinar el tiempo de ejecución de este ciclo
    auto start = std::chrono::high_resolution_clock::now();
    uint64_t m = 0;                                         // 1
    for (size_t j = 0; j < niter; j++) {                    // n
      for (size_t i = 0; i < nx; i++) {                     // n^2
			a[i] = a[i]*b[i]+c[i];                          // n^2
      }
      
    }
    auto end     = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	auto totalTimeFill_secuencial = elapsed.count();
    
    delete [] a;
	delete [] b;
	delete [] c;
    
 	// Completar esta sección
	std::cout << "Elapsed time (ms): " << (double)totalTimeFill_secuencial << "[ms]" << std::endl;
    std::cout << "Elapsed time per iteration (ms/iter): " << (double)totalTimeFill_secuencial/(niter) 
                << "[ms]" <<  std::endl;
    std::cout << "Elapsed time per iteration per point (ms/iter/operation): " <<
                (double)totalTimeFill_secuencial/(niter)/nx<< "[ms]" <<  std::endl;
	
}

