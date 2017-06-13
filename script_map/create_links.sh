awk '{print $1}' < map10k.map > 1link10k.tmp
awk '{print $1}' < map10k.map | sort > 2link10k.tmp
paste -d\- 1link10k.tmp 2link10k.tmp > final_link10k.tmp
#sed 1d 1link.tmp > 1link10k.tmp
cat final_link10k.tmp >> map10k.map
