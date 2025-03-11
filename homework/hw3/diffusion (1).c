#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int _idx(int x, int y, int z, int n) {
    int dim = (2 * n) + 1;
    int index = (x + n) * dim * dim + (y + n) * dim + (z + n);
    assert(index >= 0 && index < dim * dim * dim); // Ensure it's valid
    return index;
}



//TODO
//Implement the below function
//Simulate one particle moving n steps in random directions
//Use a random number generator to decide which way to go at every step
//When the particle stops at a final location, use the memory pointed to by grid to 
//record the number of particles that stop at this final location
//Feel free to declare, implement and use other functions when needed

void one_particle(int *grid, int n)
{
	int x = 0, y = 0, z = 0;
	
	for (int i = 0; i < n; ++i) {
		int dir = rand() % 6;
		switch (dir)
		{
			case 0: --x; break; case 1: ++x; break;
			case 2: --y; break; case 3: ++y; break;
			case 4: --z; break; case 5: ++z; break;
		}
	}
	grid[_idx(x, y, z, n)]++;


}

//TODO
//Implement the following function
//This function returns the fraction of particles that lie within the distance
//r*n from the origin (including particles exactly r*n away)
//The distance used here is Euclidean distance
//Note: you will not have access to math.h when submitting on Mimir
double density(int *grid, int n, double r)
{
	int total_particles = 0, within_radius = 0;
	double r_squared = (r * n) * (r * n);

	for (int x = -n; x <= n; ++x) {
		for (int y = -n; y <= n; ++y) {
			for (int z = -n; z <= n; ++z) {
				int idx = _idx(x, y, z, n);
				total_particles += grid[idx];

				double distance_squared = (double)(x * x + y * y + z * z);
				if (distance_squared <= r_squared) {
					within_radius += grid[idx];
				}
			}
		}
	}

	return total_particles ? (double)within_radius / total_particles : 0.0;
}


//use this function to print results
void print_result(int *grid, int n)
{
    printf("radius density\n");
    for(int k = 1; k <= 20; k++)
    {
        printf("%.2lf   %lf\n", 0.05*k, density(grid, n, 0.05*k));
    }
}

//TODO
//Finish the following function
//See the assignment decription on Piazza for more details
void diffusion(int n, int m)
{
	//fill in a few line of code below
	int dim = (2*n) + 1;
	int* grid = (int*) calloc(dim * dim * dim, sizeof(int));
	if (!grid) {
		fprintf(stderr, "Error: Memory allocation failed!\n");
		exit(EXIT_FAILURE);
	}
		for(int i = 1; i<=m; i++) one_particle(grid, n);

	print_result(grid, n);
		//fill in some code below
	free(grid);

}

int main(int argc, char *argv[])
{
	
	if(argc != 3)
	{
		printf("Usage: %s n m\n", argv[0]);
		return 0; 
	}
	int n = atoi(argv[1]);
	int m = atoi(argv[2]);

	assert(n >= 1 && n <=50);
	assert(m >= 1 && m <= 1000000);
	srand(12345);
	diffusion(n, m);
	return 0;
}