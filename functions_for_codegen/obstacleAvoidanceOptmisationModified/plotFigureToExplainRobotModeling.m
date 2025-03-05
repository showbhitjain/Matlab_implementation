 
linkSegmentsWithJoints = createLineSegmentsWithJoints(mdhparams,robot,[0.1,0.1,0.07,0.08,0.07,0,0.08],[0.1,0.1,0.06,0.04,0.05,0,0.08],Homejointpositions);

av0 = linkSegmentsWithJoints(5).aSegmentV0;
av1 = linkSegmentsWithJoints(5).aSegmentV1;
dv0 = linkSegmentsWithJoints(5).dSegmentV0;
dv1 = linkSegmentsWithJoints(5).dSegmentV1;
radiusLink = linkSegmentsWithJoints(5).radius;
radiusJoint = linkSegmentsWithJoints(5).radiusJoint;
frame4 = getTransform(robot,Homejointpositions,'robot_link4','base');

frame5 = getTransform(robot,Homejointpositions,'robot_link5','base');

hold on;
plotCylinder(av0',av1',radiusLink,'r',0.3)
%show(frankarobot,Initalconfig,'Frames','off','PreservePlot',true);
show(robot,Homejointpositions,'Frames','off','PreservePlot',true);

plotSphere(av0,radiusJoint,'r',0.3)
plotline(av0,av1,'Color','k','LineWidth',3)


plotCylinder(dv0',dv1',radiusLink,'b',0.3);
hold on;
plotSphere(dv0,radiusJoint,'b',0.3);
plotline(dv0,dv1,'Color','k','LineWidth',3);
plotSmallCoordinateSystem(frame4,0.1);
plotSmallCoordinateSystem(frame5,0.1);
plotSmallCoordinateSystem(eye(4),0.1)
% 
xlim([-0.1, 0.7]);
  ylim([-0.2, 0.2]);
 zlim([0,0.8])
view(3)
