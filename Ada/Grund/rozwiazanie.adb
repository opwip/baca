--Yaroslav Kolesnik

package body Rozwiazanie is

   task body Rondo is
      MAX_Vehicles  : Positive := MAX;
      count         : Natural := 0;
      active_street : Integer := -1;
      south_count   : Natural := 0;

      type Vehicle_Array is array (1 .. 100) of Pojazd;
      queue      : Vehicle_Array;
      head       : Natural := 1;
      tail       : Natural := 0;
      queue_size : Natural := 0;

      function queue_empty return Boolean is
      begin
         return queue_size = 0;
      end queue_empty;

      procedure enqueue (V : Pojazd) is
      begin
         if queue_size < 100 then
            tail := tail + 1;
            queue (tail) := V;
            queue_size := queue_size + 1;
         end if;
      end enqueue;

      function head_vehicle return Pojazd is
      begin
         return queue (head);
      end head_vehicle;

      procedure dequeue is
      begin
         head := head + 1;
         queue_size := queue_size - 1;
      end dequeue;

      function can_enter (V : Pojazd) return Boolean is
      begin
         if count = 0 then
            return True;
         elsif count < MAX_Vehicles and then V.Ulica = active_street then
            if V.Ulica = 2 then
               return True;
            else
               return south_count = 0;
            end if;
         end if;
         return False;
      end can_enter;

   begin
      loop
         select
            accept Wpusc (samochod : in Pojazd) do
               enqueue (samochod);
            end Wpusc;
         or
            accept Opusc (samochod : in Pojazd) do
               count := count - 1;
               if samochod.Ulica = 2 then
                  south_count := south_count - 1;
               end if;
               if count = 0 then
                  active_street := -1;
               end if;
            end Opusc;
         or
            when not queue_empty
            and then head_vehicle.Prawoskret
            and then count = 0
            =>accept ExtraEntryA (samochod : in Pojazd) do
               dequeue;
            end ExtraEntryA;
         or
            when not queue_empty
            and then not head_vehicle.Prawoskret
            and then can_enter (head_vehicle)
            =>accept ExtraEntryB (samochod : in Pojazd) do
               declare
                  V : Pojazd := head_vehicle;
               begin
                  if count = 0 then
                     active_street := V.Ulica;
                  end if;
                  count := count + 1;
                  if V.Ulica = 2 then
                     south_count := south_count + 1;
                  end if;
                  dequeue;
               end;
            end ExtraEntryB;
         or
            accept ExtraEntryC (samochod : in Pojazd) do
               null;
            end ExtraEntryC;
         or
            accept ExtraEntryD (samochod : in Pojazd) do
               null;
            end ExtraEntryD;
         or
            terminate;
         end select;
      end loop;
   end Rondo;

end Rozwiazanie;
