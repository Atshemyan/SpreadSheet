class IntCell : public Cell
{
    public:
        void set_value(int value_to_set) 
        {
            m_value = value_to_set;
        }

        int get_value()
        {
            return m_value;
        }



    private:
        int m_value;

};