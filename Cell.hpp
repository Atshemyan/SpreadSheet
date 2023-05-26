class Cell
{
    public:
            void set_value(const std::string& str)
            {
                m_value = str;
            }


            std::string get_value()
            {
                return m_value;
            }
        


    private:
        std::string m_value;

};