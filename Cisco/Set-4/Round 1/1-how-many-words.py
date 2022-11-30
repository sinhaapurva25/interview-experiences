def howMany(sentence):
    s = sentence.replace('-','')
    z = ""
    # print(s.split(" "))
    for i in s.split(" "):
        if i!="":
            # print(i[::-1][0])
            if i[::-1][0] in ['.',',','!','?']:
                z = z + i[::-1][1:][::-1] + " "
            else:
                z = z + i + " "
    return sum([1 for i in z.split(" ") if i.isalpha()])
result = howMany("j-ds ds-af lk-df kdsa fkldsf, adsbf ldka ads? asd bfdal ds bf[l. akf dhj ds 878  dwa WE DE 7475 dsfh ds  RAMU 748 dj.")
print(result)