-- Yaroslav Kolesnik
with Ada.Text_IO;         use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;
package body Rozwiazanie is

   task body Przystan is
      Current_Trip        : Integer := 0;
      Passengers_On_Board : Integer := 0;
      Tickets_Sold        : Integer := 0;
      Revenue             : Integer := 0;
      Trip_Started        : Boolean := False;
      Cruise_Ready        : Boolean := False;

   begin
      loop
         select
            accept Kasa (cena : in Integer; bilet : out Integer) do
               bilet := Current_Trip;

               if cena = 0 then

                  Cruise_Ready := True;
                  if Tickets_Sold = 0 then
                     Current_Trip := Current_Trip + 1;
                     Cruise_Ready := False;
                  end if;
               else

                  if Tickets_Sold < MAX and not Cruise_Ready then
                     Tickets_Sold := Tickets_Sold + 1;
                     Revenue := Revenue + cena;

                     if Tickets_Sold = MAX or Revenue >= WYSTARCZY then
                        Cruise_Ready := True;
                     end if;

                  else
                     bilet := Current_Trip + 1;
                     Tickets_Sold_next := Tickets_Sold_next + 1;
                     Revenue_next := Revenue_next + cena;
                  end if;
               end if;
            end Kasa;

         or
            when(not Trip_Started

                 and (Passengers_On_Board < MAX)
                 and (Tickets_Sold > Passengers_On_Board))
            =>accept Wejdz do
               Passengers_On_Board := Passengers_On_Board + 1;

               if (Passengers_On_Board = Tickets_Sold) and Cruise_Ready then
                  Trip_Started := True;

               end if;
            end Wejdz;

         or
            when Trip_Started
            =>accept Zejdz do
               Passengers_On_Board := Passengers_On_Board - 1;

               if Passengers_On_Board = 0 then
                  Current_Trip := Current_Trip + 1;
                  Tickets_Sold := Tickets_Sold_next;
                  Revenue := Revenue_next;
                  Tickets_Sold_next := 0;
                  Revenue_next := 0;
                  Trip_Started := False;
                  Cruise_Ready := False;
               end if;
            end Zejdz;

         or
            delay 1.0;
            exit;
         end select;
      end loop;
   end Przystan;

end Rozwiazanie;
