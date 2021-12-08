#include"tree_test.hpp"


class IO{

    private:

        int num_points, num_k; //maximum longitude, maximum latitude, number of data points

        std::string in_fname; //input file name

        std::vector<int>max_dim_vec;//vector of naximum value for every dimension

        friend class KDTree;



    public:

        std::vector<std::vector<int>> coord_data; // A 2-d vector to store coord data points

        IO(int num_points, int num_k , std::vector<int>max_dim_vec);//io constructor

        ~IO(); //io deconstructor

        void write_dataset ();

        void ReadFile();


};