#include <iostream>
#include <thread>
#include <mutex>


class config
{
    private:
        static config *single_instance;
        static int instance_num;
	static std::mutex mlock;
        config ();
        config (const config&) = delete;
        config operator=(const config&) = delete;
    public:
        void update_config (std::string config);
	static config* get_instance ();
};

int config::instance_num = 0;
config* config::single_instance = nullptr;
std::mutex config::mlock;

config::config ()
{
    ++instance_num;
    std::cout << "new instance created:: " << instance_num << std::endl;
}

config* config::get_instance ()
{
    if (single_instance == nullptr)
    {
        mlock.lock();
        if (single_instance == nullptr)
        {
            single_instance = new config ();
        }
        mlock.unlock();
    }
    return single_instance;
}

void config::update_config (std::string config)
{
    std::cout << "config updated:: " << config << std::endl;
    return;
}

void create_config_1 ()
{
    config *my_config_1 = config::get_instance();
    my_config_1->update_config("vivek");
}

void create_config_2 ()
{
    config *my_config_2 = config::get_instance();
    my_config_2->update_config("vivek tripathi");
}

void client_code ()
{
    std::thread t1 (create_config_1);
    std::thread t2 (create_config_2);

    t1.join ();
    t2.join ();
}

int main (int argc, char **argv)
{
    client_code ();
    return 0;
}
