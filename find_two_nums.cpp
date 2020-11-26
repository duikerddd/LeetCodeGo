  //有序序列,找出t的最早出现时间和最晚出现时间,时间复杂度O(logN)
  //解题思路: 类二分查找,一次排除一半,左右边界分两次查找
  
  void findTwoNums(){

    vector<int> arr = { 1, 2, 3, 3, 3, 3, 7 };
    vector<int> ret(2, -1);

    int left = 0, right = arr.size() - 1;

    int mid = 0;
    int t = 1;

    while (left<=right)
    {
      mid = (left + right) / 2;

      if (arr[mid]>t)
      {
        right = mid - 1;
      }
      else if (arr[mid] < t)
      {
        left = mid + 1;
      }
      else
      {
        //边界处理
        if (left == right)
        {
          ret[0] = left; break;
        }
        if (arr[mid - 1] != t)
        {
          ret[0] = mid; break;
        }
        right = mid;
      }

     }

    left = 0, right = arr.size() - 1;
    while (left<=right)
    {
      mid = (left + right) / 2;

      if (arr[mid]>t)
      {
        right = mid - 1;
      }
      else if (arr[mid] < t)
      {
        left = mid + 1;
      }
      else
      {
          //边界处理
			  if (left == right)
			  {
				  ret[1] = left; break;
			  }
			  if (arr[mid + 1] != t)
			  {
				  ret[1] = mid; break;
			  }
			  left = mid;
		  }

	  }

	  cout << ret[0] << " " << ret[1] << endl;
  }
