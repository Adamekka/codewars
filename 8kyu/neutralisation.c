#include <assert.h>
#include <stdint.h>
#include <string.h>

// s3 is return
void neutralize(const char* s1, const char* s2, char* s3) {
    assert(strlen(s1) == strlen(s2));

    uint32_t len = strlen(s1);

    s3[len] = '\0';

    for (uint8_t i = 0; i < len; i++) {
        switch (s1[i]) {
            case '+': {
                switch (s2[i]) {
                    case '+': {
                        s3[i] = '+';
                        break;
                    }

                    case '-': {
                        s3[i] = '0';
                        break;
                    }
                }
                break;
            }

            case '-': {
                switch (s2[i]) {
                    case '+': {
                        s3[i] = '0';
                        break;
                    }

                    case '-': {
                        s3[i] = '-';
                        break;
                    }
                }
                break;
            }
        }
    }
}
