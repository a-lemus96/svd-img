#ifndef COMPRESSION_H_
#define COMPRESSION_H_


// compute SVD decomposition for mxn matrix A and store result in U, S, V^T
void SVD(double **A, double **U, double **S, double **VT, int m, int n);

// take the first k SVD components and store matrices and rank k approx in 
// separate files
void compressionSVD(double **U, double **S, double **VT, int m, int n,
                    int k, const char *imagepath);

// sort idxs according to the magnitude of the associated eigenvalue
void sort(int *a, int n, double **M);


#endif
