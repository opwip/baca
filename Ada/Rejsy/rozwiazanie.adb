--Yaroslav Kolesnik

package body Rozwiazanie is

   task body Przystan is
      Cruise_Number  : Integer := 0;
      Tickets_Sold   : Natural := 0;
      Total_Revenue  : Natural := 0;
      Boarded_Count  : Natural := 0;
      Employee_Count : Natural := 0;
      Disembarking   : Boolean := False;
   begin
      loop
         if Disembarking and Boarded_Count = 0 then
            Cruise_Number := Cruise_Number + 1;
            Tickets_Sold := 0;
            Total_Revenue := 0;
            Employee_Count := 0;
            Disembarking := False;
         end if;

         select
            when not Disembarking
            and Tickets_Sold < MAX
            and Total_Revenue < WYSTARCZY
            and Employee_Count = 0
            =>accept Kasa (Cena : in Integer; Bilet : out Integer) do
               Bilet := Cruise_Number;
               Tickets_Sold := Tickets_Sold + 1;
               Total_Revenue := Total_Revenue + Cena;
               if Cena = 0 then
                  Employee_Count := Employee_Count + 1;
               end if;
               if (Tickets_Sold = MAX
                   or Total_Revenue >= WYSTARCZY
                   or Employee_Count > 0)
                 and Boarded_Count = Tickets_Sold - Employee_Count
               then
                  Disembarking := True;
               end if;
            end Kasa;
         or
            when not Disembarking
            and Boarded_Count < Tickets_Sold - Employee_Count
            =>accept Wejdz do
               Boarded_Count := Boarded_Count + 1;

               if (Tickets_Sold = MAX
                   or Total_Revenue >= WYSTARCZY
                   or Employee_Count > 0)
                 and Boarded_Count = Tickets_Sold - Employee_Count
               then
                  Disembarking := True;
               end if;
            end Wejdz;
         or
            when Disembarking and Boarded_Count > 0
            =>accept Zejdz do
               Boarded_Count := Boarded_Count - 1;
            end Zejdz;
         or
            delay 1.0;
            exit;
         end select;
      end loop;
   end Przystan;

end Rozwiazanie;
