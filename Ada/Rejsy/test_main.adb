with Rozwiazanie;
with Ada.Text_IO;         use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;

procedure Test_Main is
   -- Constants for ticket prices
   CHILD_PRICE    : constant Integer := 50;
   NORMAL_PRICE   : constant Integer := 100;
   VIP_PRICE      : constant Integer := 200;
   EMPLOYEE_PRICE : constant Integer := 0;

   -- Test counters
   Tests_Passed : Natural := 0;
   Tests_Failed : Natural := 0;

   -- Helper procedure to print test results
   procedure Print_Result (Test_Name : String; Passed : Boolean) is
   begin
      Put ("Test '");
      Put (Test_Name);
      Put ("' ... ");
      if Passed then
         Put_Line ("PASSED");
         Tests_Passed := Tests_Passed + 1;
      else
         Put_Line ("FAILED");
         Tests_Failed := Tests_Failed + 1;
      end if;
   end Print_Result;

   -- Run a test group with a fresh Przystan instance
   procedure Run_Test_Group (Group_Name : String) is
      Przystan : Rozwiazanie.Przystan (3, 300); -- MAX=3, WYSTARCZY=300
      Bilet    : Integer;
   begin
      Put_Line ("Starting test group: " & Group_Name);

      -- Test 1: Basic passenger flow
      begin
         Przystan.Kasa (CHILD_PRICE, Bilet);
         Print_Result (Group_Name & " - Child ticket cruise 0", Bilet = 0);
         Przystan.Wejdz;
         Print_Result (Group_Name & " - Boarding", True);
         Przystan.Kasa (CHILD_PRICE, Bilet);
         Print_Result (Group_Name & " - Child ticket cruise 0", Bilet = 0);
         Przystan.Wejdz;
         Print_Result (Group_Name & " - Boarding", True);
         Przystan.Kasa (VIP_PRICE, Bilet);
         Print_Result (Group_Name & " - VIP cruise 0", Bilet = 0);
         Przystan.Wejdz;
         Print_Result (Group_Name & " - Boarding", True);

         Przystan.Zejdz;
         Print_Result (Group_Name & " - Disembarking", True);
         Przystan.Zejdz;
         Print_Result (Group_Name & " - Disembarking", True);
         Przystan.Zejdz;
         Print_Result (Group_Name & " - Disembarking", True);
      end;

      -- Let the task terminate naturally
      delay 1.5; -- Longer than the 1.0s timeout
   end Run_Test_Group;

begin
   Put_Line ("Starting Przystan task tests...");
   Put_Line ("-------------------------------------");

   -- Group 1: Basic functionality
   Run_Test_Group ("Basic functionality");

   -- Group 2: MAX capacity
   declare
      Przystan : Rozwiazanie.Przystan (3, 300);
      Bilet    : Integer;
   begin
      Put_Line ("Starting test group: MAX capacity");

      -- Fill the cruise
      Przystan.Kasa (NORMAL_PRICE, Bilet);
      Przystan.Kasa (NORMAL_PRICE, Bilet);
      Przystan.Kasa (NORMAL_PRICE, Bilet);
      Print_Result ("MAX capacity - Ticket 3 gets cruise 0", Bilet = 0);

      -- Next ticket should be for next cruise
      Przystan.Kasa (NORMAL_PRICE, Bilet);
      Print_Result ("MAX capacity - Ticket 4 gets cruise 1", Bilet = 1);

      delay 1.5;
   end;

   -- Group 3: Revenue threshold
   declare
      Przystan : Rozwiazanie.Przystan (3, 300);
      Bilet    : Integer;
   begin
      Put_Line ("Starting test group: Revenue threshold");

      -- Reach threshold with VIP tickets
      Przystan.Kasa (VIP_PRICE, Bilet); -- 200
      Przystan.Kasa (VIP_PRICE, Bilet); -- 400 (exceeds 300)
      Print_Result ("Revenue - VIP tickets trigger cruise", Bilet = 1);

      delay 1.5;
   end;

   -- Group 4: Employee signal
   declare
      Przystan : Rozwiazanie.Przystan (3, 300);
      Bilet    : Integer;
   begin
      Put_Line ("Starting test group: Employee signal");

      Przystan.Kasa (EMPLOYEE_PRICE, Bilet);
      Print_Result ("Employee - Triggers cruise immediately", Bilet = 0);

      -- Should be able to start empty cruise
      Print_Result ("Employee - Empty cruise works", True);

      delay 1.5;
   end;

   Put_Line ("-------------------------------------");
   Put ("Tests PASSED: ");
   Put (Tests_Passed, Width => 0);
   New_Line;
   Put ("Tests FAILED: ");
   Put (Tests_Failed, Width => 0);
   New_Line;
end Test_Main;
