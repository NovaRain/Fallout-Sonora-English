#ifndef TEMPBOOK_H
#define TEMPBOOK_H

procedure start;
procedure use_p_proc;
procedure use_obj_on_p_proc;
procedure remove_book;


procedure start begin
end

procedure use_p_proc begin
   script_overrides;
   display_ash_mstr(700);
end

#ifdef BOOK_TYPE1
procedure use_obj_on_p_proc begin
   variable point, skill;

   if (source_obj == dude_obj) then begin
      script_overrides;
      gfade_out(ONE_GAME_SECOND);
      game_time_advance((11 - dude_iq) * ONE_GAME_HOUR);

      point := 0;
      skill := SKILL_1;

      if (has_skill(dude_obj, skill) <= 296) then begin
         point := POINT_1;
      end
      if (point > 0) then begin
         critter_mod_skill(dude_obj, skill, point);
         display_ash_mstr(READ_MSG);
      end else begin
         display_ash_mstr(701);
      end
      gfade_in(ONE_GAME_SECOND);
      scr_return(1);
   end
   call remove_book;
end
#endif

#ifdef BOOK_TYPE2
procedure use_obj_on_p_proc begin
   variable point1, skill1, point2, skill2;

   if (source_obj == dude_obj) then begin
      script_overrides;
      gfade_out(ONE_GAME_SECOND);
      game_time_advance((11 - dude_iq) * ONE_GAME_HOUR);

      point1 := 0;
      skill1 := SKILL_1;
      point2 := 0;
      skill2 := SKILL_2;

      if (has_skill(dude_obj, skill1) <= 296) then begin
         point1 := POINT_1;
         if (has_skill(dude_obj, skill2) <= 296) then begin
            point2 := POINT_2;
         end
      end
      if (point1 > 0) then begin
         critter_mod_skill(dude_obj, skill1, point1);
         if (point2 > 0) then begin
            critter_mod_skill(dude_obj, skill2, point2);
         end
         display_ash_mstr(READ_MSG);
      end else begin
         display_ash_mstr(701);
      end
      gfade_in(ONE_GAME_SECOND);
      scr_return(1);
   end
   call remove_book;
end
#endif

procedure remove_book begin
   variable itemHand, itemCarry;

   itemCarry := obj_carrying_pid_obj(dude_obj, BOOK_PID);
   if (rm_mult_objs_from_inven(dude_obj, itemCarry, 0) > 1) then begin
      itemHand := critter_inven_obj(dude_obj, INVEN_TYPE_RIGHT_HAND);
      if (obj_pid(itemHand) == BOOK_PID) then begin
         rm_obj_from_inven(dude_obj, itemHand);
         destroy_object(itemHand);
      end else begin
         itemHand := critter_inven_obj(dude_obj, INVEN_TYPE_LEFT_HAND);
         if (obj_pid(itemHand) == BOOK_PID) then begin
            rm_obj_from_inven(dude_obj, itemHand);
            destroy_object(itemHand);
         end
      end
   end
end

#endif // TEMPBOOK_H
