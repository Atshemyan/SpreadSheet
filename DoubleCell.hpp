class DoubleCell : public Cell
{
public:
    void set_value(double double_to_set)
    {
        m_value = double_to_set;
    }

    double get_value()
    {
        return m_value;
    }



private:
    double m_value;
};