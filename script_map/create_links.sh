awk '{print $1}' < map1k.map > 1link1k.tmp
awk '{print $1}' < map1k.map | sort > 2link1k.tmp
paste -d\- 1link1k.tmp 2link1k.tmp > final_link1k.tmp
sed 1d 1link.tmp > 1link1k.tmp
cat final_link1k.tmp >> map1k.map
