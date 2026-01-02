st = input()

c_a_list = ["c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="]

for i in c_a_list:
    while i in st:
        st = st.replace(i, ".")

print(len(st))

