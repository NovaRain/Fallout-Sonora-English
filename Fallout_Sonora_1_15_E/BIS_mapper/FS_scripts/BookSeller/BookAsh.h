#ifndef BOOKASH_H
#define BOOKASH_H

/* Items */
#define PID_BOOK_TRAP          (517)
#define PID_BOOK_SCIE          (518)
#define PID_BOOK_ENER          (519)
#define PID_BOOK_BART          (520)
#define PID_BOOK_GUNS          (521)
#define PID_BOOK_MEDI          (522)
#define PID_BOOK_REPR          (523)
#define PID_BOOK_SCUT          (524)
#define PID_BOOK_UNAR          (525)
#define PID_BOOK_LOCK          (526)

/* Critter */
#define PID_ASHLEY             (16777374)
#define PID_ASHLEY_DOG         (16777375)

/* Scripts */
#define SCRIPT_BookAsh         (780)
#define SCRIPT_BookBox         (781)
#define SCRIPT_BookDog         (782)
#define SCRIPT_BookTrap        (783)
#define SCRIPT_BookScie        (784)
#define SCRIPT_BookEner        (785)
#define SCRIPT_BookBart        (786)
#define SCRIPT_BookGuns        (787)
#define SCRIPT_BookMedi        (788)
#define SCRIPT_BookRepr        (789)
#define SCRIPT_BookScut        (790)
#define SCRIPT_BookUnar        (791)
#define SCRIPT_BookLock        (792)

/* Global Variables - sfall */
#define book_ash_spawned       get_sfall_global_int("ashbook1")
#define set_book_ash_spawned   set_sfall_global("ashbook1", 1)
#define book_ash_attack        get_sfall_global_int("ashattak")
#define set_book_ash_attack    set_sfall_global("ashattak", 1)
#define book_ash_dead          ((get_sfall_global_int("ashdead1") bwand bit_1) != 0)
#define set_book_ash_dead      set_sfall_global("ashdead1", get_sfall_global_int("ashdead1") bwor bit_1)
#define book_dog_dead          ((get_sfall_global_int("ashdead1") bwand bit_2) != 0)
#define set_book_dog_dead      set_sfall_global("ashdead1", get_sfall_global_int("ashdead1") bwor bit_2)


#define ash_mstr(x)                message_str(SCRIPT_BookAsh,x)
#define display_ash_mstr(x)        display_msg(ash_mstr(x))

#endif // BOOKASH_H
