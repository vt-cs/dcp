# S x A = R

S = str(input())[::-1]
A = str(input())[::-1]

f_out = []

result = []
for i in range(len(S)+len(A)):
    result.append(0)

for idx_a, val_a in enumerate(A):
    res = 0
    carry = 0
    rem = 0
    flag = 1
    z = idx_a
    m_out = []
    for val_s in S:
        if flag == 1:
            while z > 0:
                m_out.append(0)
                z = z-1
            flag = 0
        res = int(val_a)*int(val_s) + carry
        rem = res%10
        carry = res//10
        m_out.append(rem)
    if carry > 0:
        m_out.append(carry)
    f_out.append(m_out)

for l in f_out:
    carry = 0
    rem = 0
    for i_l, v_l in enumerate(l):
        res = result[i_l]+int(v_l)+carry
        rem = res%10
        carry = res//10
        result[i_l] = rem

print (*result[::-1])
