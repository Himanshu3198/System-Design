class Allocator
{
    public:
        int totSize;
    vector<int> arr;
    Allocator(int n)
    {
        totSize = n;
        arr.resize(n, -1);
    }

    int allocate(int size, int mID)
    {

        for (int i = 0; i < totSize; i++)
        {
            int occ = 0, strt = i, j = i;
            if (arr[i] == -1)
            {

                strt = i;
                while (i < totSize && arr[i] == -1)
                {
                    occ++;
                    i++;
                    if (occ == size) break;
                }
                if (occ >= size)
                {
                    for (int k = strt; k < strt + size; k++)
                    {
                        arr[k] = mID;
                    }
                    return strt;
                }
            }
        }

        return -1;
    }

    int free(int mID)
    {

        int rem = 0;
        for (int i = 0; i < totSize; i++)
        {
            if (arr[i] == mID)
            {
                arr[i] = -1;
                rem++;
            }
        }
        return rem;
    }
};

/**
 *Your Allocator object will be instantiated and called as such:
 *Allocator* obj = new Allocator(n);
 *int param_1 = obj->allocate(size,mID);
 *int param_2 = obj->free(mID);
 */
