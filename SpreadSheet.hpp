#include <iostream>
#include <string>
#include <vector>
#include "Cell.hpp"
#include "IntCell.hpp"
#include "DoubleCell.hpp"

class Spreadsheet
{
    public:
        Spreadsheet(int row, int column) : m_cells(row, std::vector<Cell*>(column))
        {
            Cell* cp = new Cell();
            for (auto& row : m_cells)
            {
                for (auto& cell : row)
                {
                    cell = cp;
                }
            }

            m_spreadsheet_height = row;
            m_spreadsheet_width = column;
            cp = nullptr;
        }


        void AddColumn()
        {
            m_capacity = m_spreadsheet_width;
            Cell* cp = new Cell();
            for (int i = 0; i < m_spreadsheet_height; i++)
            {
               m_cells[i].push_back(cp);
            }
            m_spreadsheet_width++;
            cp = nullptr;

        }

        void AddColumn(int counter)
        {
            m_capacity = m_spreadsheet_width;
            Cell* cp = new Cell();
            for (int i = 0; i < counter; i++)
            {
                for (int i = 0; i < m_spreadsheet_height; i++)
                {
                    m_cells[i].push_back(cp);
                }
                m_spreadsheet_width++;
            }
            cp = nullptr;


        }

        void AddRow()
        {
            Cell* cp = new Cell();
            m_capacity = m_spreadsheet_height; 
            std::vector<Cell*> new_row(m_spreadsheet_width, cp);
            m_cells.push_back(new_row);
            m_spreadsheet_height++;
            cp = nullptr;
        }

        void AddRow(int counter)
        {
            Cell* cp = new Cell();
            m_capacity = m_spreadsheet_height; 
            for (int i = 0; i < counter; i++)
            {
                std::vector<Cell*> new_row(m_spreadsheet_width, cp);
                m_cells.push_back(new_row);
                m_spreadsheet_height++;
            }
            
            cp = nullptr;
        }


        void CheckValid(int row, int column)
        {
            try 
            {
                if (row < 0 || row >= m_spreadsheet_width || column < 0 || column >= m_spreadsheet_width)
                {
                    throw std::out_of_range("Error: cell out of bounds!");
                }
            } 
            catch (std::out_of_range& e) 
            { 
                std::cout << e.what() << std::endl; 
            }
        }

        void SetCellAt(int row, int column, Cell* cp)
        {
            CheckValid(row, column);
            m_cells[row][column] = cp;
        
        }
        void SetCellAt(int row, int column, const std::string& str)
        {
            Cell* pt = new Cell();
            pt->set_value(str);
            CheckValid(row, column);
            m_cells[row][column] = pt;
            pt = nullptr;

        }

        void SetCellAt(int row, int column, int num_to_set)
        {
            CheckValid(row, column);
            std::cout << "SetCellAt with int is Working \n";
            static_cast<IntCell*>(m_cells[row][column])->set_value(num_to_set);
        }

        void SetCellAt(int row, int column, double double_to_set)
        {
            CheckValid(row, column);
            DoubleCell* pt = new DoubleCell();
            pt->set_value(double_to_set);
            m_cells[row][column] = pt;
            pt = nullptr;

        }
        template<typename T>

        T* GetCellAt(int row, int column)
        {
            CheckValid(row, column);
            return static_cast<T*>(m_cells[row][column]);
            
        }

        
        void Print()
        {
            for (int i = 0; i < m_spreadsheet_height; i++)
            {
                for (int j = 0; j < m_spreadsheet_width; j++)
                {
                    std::cout << m_cells[i][j]->get_value() << "|";

                }

                std::cout << "\n";
                
            }
            
        }



        
    private:
        std::vector<std::vector<Cell*>> m_cells;
        int m_spreadsheet_height;
        int m_spreadsheet_width;
        int m_capacity;


};