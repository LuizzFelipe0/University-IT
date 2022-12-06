declare BSORT=()
function bubble_sort()
{   
    (($# > 0)) && BSORT=("$@")
    local j=0 sort=$((${#BSORT[*]} - 1)) 
    while ((sort > 0))
    do
        local i=0
        while ((i < sort))
        do
            if [ "${BSORT[$i]}" \> "${BSORT[$((i + 1))]}" ]
            then
                local t="${BSORT[$i]}"
                BSORT[$i]="${BSORT[$((i + 1))]}"
                BSORT[$((i + 1))]="$t"
            fi
            ((++i))
        done
        ((++j))
        ((--sort))
    done
    
}
echo "Insira um valor para o programa ordenar (string e/ou número) :"
read valor 
bubble_sort ${valor}
echo ${BSORT[@]}





