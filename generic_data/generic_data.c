#include <stdio.h>
#include <stdlib.h>

struct generic_data
{
    void *ptr_to_data;
    size_t data_length;
};

struct generic_data* new_generic_data()
{
    struct generic_data *new_generic_data_ptr = NULL;
    new_generic_data_ptr = (struct generic_data*) malloc (sizeof (struct generic_data));
    if (new_generic_data_ptr != NULL)
    {
        printf ("%s: created a new generic_data object\n", __func__);
        new_generic_data_ptr->ptr_to_data = NULL;
	new_generic_data_ptr->data_length = 0;
    }
    return new_generic_data_ptr;
}

void delete_generic_data (struct generic_data **data)
{
    if (data == NULL || *data == NULL)
    {
        printf ("%s: nothing to free. returning\n", __func__);
        return;
    }
    else if ((*data)->ptr_to_data == NULL)
    {
        printf ("%s: no data. freeing generic_data struct.\n", __func__);
        free (*data);
	*data = NULL;
	return;
    }
    else
    {
        printf ("%s: freeing associated data.\n", __func__);
        free ((*data)->ptr_to_data);
        (*data)->ptr_to_data = NULL;
        printf ("%s: freeing generic_data struct.\n", __func__);
        free (*data);
	*data = NULL;
	return;
    }
}


int main (int argc, char **argv)
{
    struct generic_data *data_ptr = NULL;
    data_ptr = new_generic_data();
    delete_generic_data(&data_ptr);

    return 0;
}
