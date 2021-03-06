! { dg-do run }
! { dg-options "-finit-real=inf" }
! { dg-add-options ieee }

program init_flag_4
  call real_test
end program init_flag_4

! Test some initializations for both implicitly and
! explicitly declared local variables.
subroutine real_test
  real r1
  real r2(10)
  dimension r3(10,10)
  if (r1 .le. 0 .or. r1 .ne. 2*r1) call abort
  if (r2(2) .le. 0 .or. r2(2) .ne. 2*r2(2)) call abort
  if (r3(5,5) .le. 0 .or. r3(5,5) .ne. 2*r3(5,5)) call abort
  if (r4 .le. 0 .or. r4 .ne. 2*r4) call abort
end subroutine real_test
