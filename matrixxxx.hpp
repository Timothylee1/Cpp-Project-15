/*!*************************************************************************
****
\file matrix.hpp
\author Jeffry Hermann
\par SIT email: 2101665@sit.singaportech.edu.sg
\par Course: RSE1202
\par Programming Assignment 8
\date 21-03-2022

 \brief
  This source file represents the implementation and declaration 
  (of class template matrix) that are used in matrix-driver.cpp.

  In summary, these functions
	Creates member functions for the template class matrix, using DRY principle
    with vector<vector<>>
*******************************************************************************/
#ifndef MATRIX_HPP__
#define MATRIX_HPP__

#include <iostream>
#include <vector>

namespace hlp2{
    template<typename T>
    class matrix{
    public:

        // constructor
        matrix(size_t r, size_t c);
        // copy constructor
        matrix(matrix<T> const& rhs);

        // subscript overload
        std::vector<T>& operator[](size_t index);
        const std::vector<T>& operator[](size_t index) const;

        void operator=(matrix<T> const& rhs);
        bool operator==(matrix<T> const& rhs)const;
        bool operator!=(matrix<T> const& rhs);
        matrix<T> operator+(matrix<T> const& rhs);
        matrix<T>& operator+=(matrix<T> const& rhs);
        matrix<T> operator-(matrix<T> const& rhs);
        matrix<T>& operator-=(matrix<T> const& rhs);
        matrix<T> operator*(matrix<T> const& rhs);

        matrix<T>& operator*=(matrix<T> const& rhs);
        matrix<T>& operator*=(T rhs);

        // accessor
        size_t Rows() const;
        size_t Cols() const;

     private:
        size_t rows;
        size_t cols;
        std::vector<std::vector<T>> mdata;
    };


    /***************************************************************
     @brief default constructor

     @return Void 
    ****************************************************************/
    template<typename T>
    matrix<T>::matrix(size_t r, size_t c):
    rows {r}, cols {c}, mdata {r, std::vector<T>(c)}{}

    /***************************************************************
     @brief Copy constructor

     @param rhs 
            reference to a const matrix class 

     @return Void 
    ****************************************************************/
    template<typename T>
    matrix<T>::matrix(matrix<T> const& rhs):
    rows{rhs.rows}, cols{rhs.cols}, mdata{rows,std::vector<T>(cols)}
    {
        for(size_t i{}; i < rows; ++i){
            for(size_t j{}; j < cols; ++j){
                this->mdata[i][j] = rhs[i][j];
            }
        }
    }

    /***************************************************************
     @brief Subscript operator 

     @param index 
            index of the value to return   

     @return std::vector<T>&,
             the data at the index specified 
    ****************************************************************/
    template<typename T>
    std::vector<T>& matrix<T>::operator[](size_t index){
        return mdata[index];
    }

    /***************************************************************
     @brief const overloaded Subscript operator 

     @param index 
            index of the value to return   

     @return const std::vector<T>&,
             the data at the index specified 
    ****************************************************************/
    template<typename T>
    const std::vector<T>& matrix<T>::operator[](size_t index) const{
        return mdata[index];
    }


    /***************************************************************
     @brief  operator= overload 

     @param rhs
            matrix<T> const& type representing matrix   

     @return void
    ****************************************************************/
    template<typename T>
    void matrix<T>::operator=(matrix<T> const& rhs){
        this->rows = rhs.rows;
        this->cols = rhs.cols;
        for(size_t i{}; i < this->rows; ++i){
            for(size_t j{}; j < this->cols; ++j){
                this->mdata[i][j] = rhs[i][j]; 
            }
        }
    }

    /***************************************************************
     @brief  operator== overload , checks if matrix are equal

     @param rhs
            matrix<T> const& type representing matrix   

     @return bool type true or false
    ****************************************************************/
    template<typename T>
    bool matrix<T>::operator==(matrix<T> const& rhs)const{
         if((this->rows == rhs.rows)&&(this->cols == rhs.cols)){
            for(size_t i{}; i < this->rows; ++i){
                for(size_t j{}; j < this->cols; ++j){
                    if( this->mdata[i][j] == rhs[i][j]){
                        continue;
                    }
                    else{
                        return false;
                    } 
                }
            }
            return true;
        }
        else{
            return false;
        }
    }
    
    /***************************************************************
     @brief  operator!= overload , checks if matrix are not equal

     @param rhs
            matrix<T> const& type representing matrix   

     @return bool type true or false
    ****************************************************************/
    template<typename T>
    bool matrix<T>::operator!=(matrix<T> const& rhs){
        if(*this == rhs){
            return false;
        }
        else{
            return true;
        }
    }

    
    /***************************************************************
     @brief  operator+ overload , adds the matrix elements

     @param rhs
            matrix<T> const& type representing matrix   

     @return tmp matrix containing sum of matrix
    ****************************************************************/
    template<typename T>
    matrix<T> matrix<T>::operator+(matrix<T> const& rhs){
        matrix<T> tmp(this->rows,this->cols);

        for(size_t i{}; i < this->rows; ++i){
            for(size_t j{}; j < this->cols; ++j){
                tmp[i][j] = this->mdata[i][j] + rhs[i][j];
            }
        }
        return tmp;
    }

    /***************************************************************
     @brief  operator+= overload

     @param rhs
            matrix<T> const& type representing matrix   

     @return reference to matrix obj that called the overload
    ****************************************************************/
    template<typename T>
    matrix<T>& matrix<T>::operator+=(matrix<T> const& rhs){

        for(size_t i{}; i < rows; ++i){
            for(size_t j{}; j < cols; ++j){
                this->mdata[i][j] += rhs[i][j];
            }
        }
        return *this;
    }

    /***************************************************************
     @brief  operator- overload

     @param rhs
            matrix<T> const& type representing matrix   

     @return tmp matrix after deducting the matrix elements
    ****************************************************************/
    template<typename T>
    matrix<T> matrix<T>::operator-(matrix<T> const& rhs){

      matrix<T> tmp(this->rows,this->cols);

        for(size_t i{}; i < this->rows; ++i){
            for(size_t j{}; j < this->cols; ++j){
                tmp[i][j] = this->mdata[i][j] - rhs[i][j];
            }
        }
        return tmp;
    }

    
    /***************************************************************
     @brief  operator-= overload

     @param rhs
            matrix<T> const& type representing matrix   

     @return reference to matrix obj that called the overload
    ****************************************************************/
    template<typename T>
    matrix<T>& matrix<T>::operator-=(matrix<T> const& rhs){

        for(size_t i{}; i < rows; ++i){
            for(size_t j{}; j < cols; ++j){
                this->mdata[i][j] -= rhs[i][j];
            }
        }
        return *this;
    }

    
    /***************************************************************
     @brief  operator* overload

     @param rhs
            matrix<T> const& type representing matrix   

     @return tmp matrix after multiplying the matrix elements
    ****************************************************************/
    template<typename T>
    matrix<T> matrix<T>::operator*(matrix<T> const& rhs){

        matrix<T> tmp(this->rows,rhs.cols);

        for(size_t i{}; i < this->rows; ++i){
            for(size_t j{}; j < rhs.cols; ++j){
                for(size_t k{}; k < this->cols; ++k){
                    tmp.mdata[i][j] += this->mdata[i][k] * rhs.mdata[k][j];
                }
            }
        }
        return tmp;
    }
    
    /***************************************************************
     @brief  operator*= overload that multiplies matrix against 
     another matrix

     @param rhs
            matrix<T> const& type representing matrix   

     @return reference to matrix obj that called the overload
    ****************************************************************/
    template<typename T>
    matrix<T>& matrix<T>::operator*=(matrix<T> const& rhs){
        *this = *this * rhs;
        return *this;
    }

    
    /***************************************************************
     @brief  operator*= overload that multiplies value across whole
     matrix

     @param rhs
            matrix<T> const& type representing matrix   

     @return reference to matrix obj that called the overload
    ****************************************************************/
    template<typename T>
    matrix<T>& matrix<T>::operator*=(T rhs){
        *this = *this * rhs;
        return *this;
    }

    

    /***************************************************************
     @brief  operator* overload Use to multiply a matrix with a 
     value on the rhs

     @param lhs
            matrix<T> const& type representing matrix

     @param rhs
            T type value to multiply   

     @return tmp matrix after multiplying the matrix elements
    ****************************************************************/
    template<typename T>
    matrix<T> operator*(matrix<T>const& lhs, T rhs){
        matrix<T> tmp(lhs.Rows(), lhs.Cols()); 

        for(size_t i{}; i<lhs.Rows(); ++i){
            for(size_t j{}; j<lhs.Cols(); ++j){
                tmp[i][j] = lhs[i][j] * rhs;
            }
        }
        return tmp;
    }

    
    /***************************************************************
     @brief  operator* overload Use to multiply a value with matrix 
     on the rhs

     @param lhs
            T type value to multiply

     @param rhs
            matrix<T> const& type representing matrix   

     @return tmp matrix after multiplying the matrix elements
    ****************************************************************/
    template<typename T>
    matrix<T> operator*(T lhs, matrix<T>& rhs){
        matrix<T> tmp(rhs.Rows(), rhs.Cols()); 
        for(size_t i{}; i < rhs.Rows(); ++i){
            for(size_t j{}; j < rhs.Cols(); ++j){
                tmp[i][j] = lhs * rhs[i][j];
            }
        }
        return tmp;
    }

    /***************************************************************
     @brief  operator<< overload for outstream printing

     @param os
            std::ostream& type representing the outstream

     @param rhs
            matrix<T> const& type representing matrix   

     @return std::ostream& os
    ****************************************************************/
    template<typename T>
    std::ostream& operator<<(std::ostream& os, matrix<T> const& rhs){
        for(size_t i{}; i < rhs.Rows(); ++i){
            for(size_t j{}; j < rhs.Cols(); ++j){
                if(j > 0){
                    os << " ";
                }   
                os<<rhs[i][j];
            }
            os<<"\n";
        }
        return os;
    }
    
    /***************************************************************
     @brief  Accessor for priv data rows

     @return size_t type value of priv data rows
    ****************************************************************/
    template<typename T>
    size_t matrix<T>::Rows() const{
        return rows;
    }

    /***************************************************************
     @brief  Accessor for priv data cols

     @return size_t type value of priv data cols
    ****************************************************************/
    template<typename T>
    size_t matrix<T>::Cols() const{
        return cols;
    }


}// end of hlp2
// note: all functions MUST be defined outside the class definition!!!
#endif