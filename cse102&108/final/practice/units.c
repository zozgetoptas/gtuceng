#include <stdio.h>
#include <string.h>

#define NAME_LEN 30
#define ABBREV_LEN 15
#define CLASS_LEN 20
#define NOT_FOUND -1
#define MAX_UNITS 20

typedef struct{
    char name[NAME_LEN], abbrev[ABBREV_LEN], class[CLASS_LEN];
    double standard;
} unit_t;

int fscanf_unit(FILE *filep, unit_t *unitp);
void load_units(int unit_max, unit_t units[], int *unit_sizep);
int search(const unit_t units[], const char *target, int n);
double convert(double quantity, double old_stand, double new_stand);

int main()
{
    unit_t units[MAX_UNITS];
    int num_units;
    char old_units[NAME_LEN], new_units[NAME_LEN];
    int status, old_index, new_index;
    double quantity;
    
    // HATA 1 DÜZELTİLDİ: Başındaki "void" kaldırıldı
    load_units(MAX_UNITS, units, &num_units);
    
    printf("enter a conversion problem or q\n");
    printf("to convert 25 kilograms to miles, youd enter\n> 25 kilometers miles\n");
    printf("    or, alternatively,\n> 25 km mi\n");
    
    for(status = scanf("%lf%s%s", &quantity, old_units, new_units); status == 3; status = scanf("%lf%s%s", &quantity, old_units, new_units))
    {
        printf("attempting conversion of %.4f %s to %s...\n", quantity, old_units, new_units);
        old_index = search(units, old_units, num_units);
        
        // GİZLİ HATA DÜZELTİLDİ: old_units yerine new_units aratılmalıydı
        new_index = search(units, new_units, num_units);
        
        if(old_index == NOT_FOUND)
            printf("unit %s not in database\n", old_units);
        else if(new_index == NOT_FOUND)
            printf("unit %s not in database\n", new_units);
        else if(strcmp(units[old_index].class, units[new_index].class) != 0)
            printf("cannot convert %s (%s) to %s (%s)\n", old_units, units[old_index].class, new_units, units[new_index].class);
        else
            // HATA 2 DÜZELTİLDİ: mew_units yerine new_units yazıldı
            printf("%.4f %s = %.4f %s\n", quantity, old_units, convert(quantity, units[old_index].standard, units[new_index].standard), new_units);
            
        printf("\nenter a conversion problem or q to quit.\n");
    }
    return 0;
}

// GİZLİ HATA DÜZELTİLDİ: Fonksiyon adı "fsancf" yerine "fscanf_unit" olarak düzeltildi
int fscanf_unit(FILE *filep, unit_t *unitp)
{
    int status = fscanf(filep, "%s%s%s%lf", unitp->name, unitp->abbrev, unitp->class, &unitp->standard);
    if(status == 4)
        status = 1;
    else if(status != EOF)
        status = 0;
    return status;
}

void load_units(int unit_max, unit_t units[], int *unit_sizep)
{
    FILE *inp = fopen("units.dat", "r");
    unit_t data;
    int i = 0, status;
    for(status = fscanf_unit(inp, &data); status == 1 && i < unit_max; status = fscanf_unit(inp, &data))
        units[i++] = data;
    fclose(inp);
    
    if(status == 0)
        printf("error\n using first %d data values\n", i);
    else if(status != EOF)
        printf("\n error: too much data in file\nusing first %d data values\n", i);
        
    *unit_sizep = i;
}

int search(const unit_t units[], const char *target, int n)
{
    int i = 0, found = 0, where;
    
    while(!found && i < n)
    {
        if(strcmp(units[i].name, target) == 0 || strcmp(units[i].abbrev, target) == 0)
            found = 1;
        else
            ++i;
    }
    
    if(found)
        where = i;
    else
        where = NOT_FOUND;
        
    return where;
}

double convert(double quantity, double old_stand, double new_stand)
{
    return(quantity * old_stand / new_stand);
}
