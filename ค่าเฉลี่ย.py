import numpy as np
import matplotlib.pyplot as plt
men_means, men_std = (7.0, 6.2, 8.1), (0.5, 0.5, 0.5)
ind = np.arange(len(men_means))  # ตำแหน่งของกลุ่ม
width = 0.35  # ความกว้างของแท่งกราฟ
fig, ax = plt.subplots()
rects1 = ax.bar(ind - width/2 , men_means, width, yerr=men_std, color='SkyBlue', label='pH')
# กำหนดข้อความที่แสดงบริเวณด้านข้างกับด้านบนรวมถึงการกำหนดชื่อข้อมูลในแต่ละตัว
ax.set_ylabel('pH')
ax.set_title('Bar chart comparing the average pH values\n​​of each type of fertilizer.')
ax.set_xticks(ind)
ax.set_xticklabels(('Animal manure', 'Composted leaf fertilizer', 'Microbial fertilizer'))
ax.legend()
def autolabel(rects, xpos='center'):
    xpos = xpos.lower()  #ปรับขนาดของตัวอักษีที่จะพิมพ์เป็นขนาดมาตรฐาน
    ha = {'center': 'center', 'right': 'left', 'left': 'right'}
    offset = {'center': 0.5, 'right': 0.57, 'left': 0.43}  # x_txt = x + w*off
    for rect in rects:
        height = rect.get_height()
        ax.text(rect.get_x() + rect.get_width()*offset[xpos], 1.01*height,
                '{}'.format(height), ha=ha[xpos], va='bottom')
#กำหนดแท่งกราฟที่จะแสดงโดยให้ rects1 เพศชายแสดงด้านซ้าน ส่วน rects2 เพศหญิงแสดงที่ด้านขวา
autolabel(rects1, "left")
plt.show()