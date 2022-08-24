typedef volatile uint32_t io_wo_32 ;

typedef const volatile uint32_t io_ro_32 ;

typedef volatile uint32_t io_rw_32 ;











typedef struct {

   







    io_rw_32 accum[2];



   







    io_rw_32 base[3];



   







    io_ro_32 pop[3];



   







    io_ro_32 peek[3];



   

    io_rw_32 ctrl[2];



   









    io_rw_32 add_raw[2];



   



    io_wo_32 base01;

} interp_hw_t;

typedef struct {

   



    io_ro_32 cpuid;



   





    io_ro_32 gpio_in;



   





    io_ro_32 gpio_hi_in;



    uint32_t _pad0;



   





    io_rw_32 gpio_out;



   





    io_wo_32 gpio_set;



   





    io_wo_32 gpio_clr;



   





    io_wo_32 gpio_togl;



   





    io_rw_32 gpio_oe;



   





    io_wo_32 gpio_oe_set;



   





    io_wo_32 gpio_oe_clr;



   





    io_wo_32 gpio_oe_togl;



   





    io_rw_32 gpio_hi_out;



   





    io_wo_32 gpio_hi_set;



   





    io_wo_32 gpio_hi_clr;



   





    io_wo_32 gpio_hi_togl;



   





    io_rw_32 gpio_hi_oe;



   





    io_wo_32 gpio_hi_oe_set;



   





    io_wo_32 gpio_hi_oe_clr;



   





    io_wo_32 gpio_hi_oe_togl;



   











    io_rw_32 fifo_st;



   



    io_wo_32 fifo_wr;



   



    io_ro_32 fifo_rd;



   



    io_ro_32 spinlock_st;



   



    io_rw_32 div_udividend;



   



    io_rw_32 div_udivisor;



   



    io_rw_32 div_sdividend;



   



    io_rw_32 div_sdivisor;



   



    io_rw_32 div_quotient;



   



    io_rw_32 div_remainder;



   







    io_ro_32 div_csr;

    uint32_t _pad1;

    interp_hw_t interp[2];

} sio_hw_t;
