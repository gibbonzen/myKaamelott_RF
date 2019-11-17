#ifndef RADIO_UTILS_H
#define RADIO_UTILS_H

class RadioUtils {
  public: 
    static void decode(String args, int size, uint8_t* &arr);

  private: 
    static void compute(String eq, int len, uint8_t* &arr);
};

void RadioUtils::decode(String args, int size, uint8_t* &arr) {
  const char delimiter = ';';
  
  int arrSize = 0;
  int lastDelimiter = 0;
  for(int i = 0; i < size; i++) {
    char c = args[i];

    if(c == delimiter) {
      if(arrSize == 0) {
        String s = args.substring(0, i);
        arrSize = s.toInt();
        arr = new uint8_t[arrSize];
        lastDelimiter = i+1;
      }

      else {
        int len = i-lastDelimiter;
        String w = args.substring(lastDelimiter, i);
        lastDelimiter = i+1;
        RadioUtils::compute(w, len, arr);
      }
    }

    if(i == size-1) {
      int len = size-lastDelimiter;
      String w = args.substring(lastDelimiter);
      RadioUtils::compute(w, len, arr);
    }
  }
}

void RadioUtils::compute(String eq, int len, uint8_t* &arr) {
  char delimiter = '=';

  int index = 0;
  int eqPos = 0;
  for(int i = 0; i < len; i++) {
    char c = eq[i];

    if(delimiter == c) {
      String strIndex = eq.substring(0, i);
      index = strIndex.toInt();
      eqPos = i+1;
    }

    if(eqPos != 0) {
      String v = eq.substring(eqPos);
      arr[index] = v.toInt();
      break;
    }
  }
}

#endif